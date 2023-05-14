#pragma once

#include <unordered_map>
#include <mutex>
#include <functional>
#include <atomic>
#include <algorithm>
#include <vector>
#include <thread>

template <class K, class V, class Hash = std::hash<K>>
class ConcurrentHashMap {
public:
    ConcurrentHashMap(const Hash& hasher = Hash()) : ConcurrentHashMap(kUndefinedSize, hasher) {
    }

    explicit ConcurrentHashMap(int expected_size, const Hash& hasher = Hash())
        : ConcurrentHashMap(expected_size, kDefaultConcurrencyLevel, hasher) {
    }

    ConcurrentHashMap(int expected_size, int expected_threads_count, const Hash& hasher = Hash())
        : hasher_(hasher),
          mutex_(std::min(static_cast<int>(std::thread::hardware_concurrency()),
                          expected_threads_count)) {
        count_thr_ =
            std::min(static_cast<int>(std::thread::hardware_concurrency()), expected_threads_count);
        capacity_ = count_thr_;
        if (expected_size > capacity_ * 2) {
            capacity_ = 2 * capacity_ * (expected_size / capacity_ + 1);
        }
        table_.resize(capacity_);
    }

    bool Insert(const K& key, const V& value) {
        std::unique_lock<std::mutex> lock(mutex_[hasher_(key) % mutex_.size()]);
        auto it = std::find_if(table_[hasher_(key) % capacity_].begin(),
                               table_[hasher_(key) % capacity_].end(),
                               [key](const auto& i) { return key == i.first; });
        if (it != table_[hasher_(key) % capacity_].end()) {
            return false;
        }
        ++size_;
        table_[hasher_(key) % capacity_].emplace_back(key, value);
        if (size_ * 2 > capacity_) {
            lock.unlock();
            Rehash();
        }
        return true;
    }

    bool Erase(const K& key) {
        std::unique_lock<std::mutex> lock(mutex_[hasher_(key) % mutex_.size()]);
        size_t ind = hasher_(key) % capacity_;
        auto it = std::find_if(table_[ind].begin(), table_[ind].end(),
                               [key](const auto& i) { return key == i.first; });
        if (it == table_[hasher_(key) % capacity_].end()) {
            return false;
        }
        ++size_;
        table_[ind].erase(it);
        return true;
    }

    void Clear() {
        AllLock();
        size_ = 0;
        table_.clear();
        capacity_ = kDefaultConcurrencyLevel;
        table_.resize(capacity_);
        AllUnlock();
    }

    std::pair<bool, V> Find(const K& key) const {
        std::unique_lock<std::mutex> lock(mutex_[hasher_(key) % mutex_.size()]);
        auto it = std::find_if(table_[hasher_(key) % capacity_].begin(),
                               table_[hasher_(key) % capacity_].end(),
                               [key](const auto& i) { return i.first == key; });
        if (it == table_[hasher_(key) % capacity_].end()) {
            return {false, V()};
        }
        return {true, it->second};
    }

    const V At(const K& key) const {
        std::unique_lock<std::mutex> lock(mutex_[hasher_(key) % mutex_.size()]);
        auto it = std::find_if(table_[hasher_(key) % capacity_].begin(),
                               table_[hasher_(key) % capacity_].end(),
                               [key](const auto& i) { return i.first == key; });
        if (it == table_[hasher_(key) % capacity_].end()) {
            throw std::out_of_range("out of range");
        }
        return it->second;
    }

    size_t Size() const {
        return size_.load();
    }

    static const int kDefaultConcurrencyLevel;
    static const int kUndefinedSize;

private:
    void Rehash() {
        AllLock();
        std::vector<std::vector<std::pair<K, V>>> new_table(capacity_ * 2);
        for (auto& list : table_) {
            for (auto& pair : list) {
                new_table[hasher_(pair.first) % (capacity_ * 2)].emplace_back(pair);
            }
        }
        capacity_ = capacity_ * 2;
        table_.clear();
        table_ = std::move(new_table);
        AllUnlock();
    }

    void AllLock() {
        for (auto& m : mutex_) {
            m.lock();
        }
    }
    void AllUnlock() {
        for (auto& m : mutex_) {
            m.unlock();
        }
    }

private:
    Hash hasher_;
    size_t count_thr_;
    std::atomic<size_t> size_ = 0;
    std::atomic<size_t> capacity_;
    mutable std::vector<std::mutex> mutex_;
    std::vector<std::vector<std::pair<K, V>>> table_;
};

template <class K, class V, class Hash>
const int ConcurrentHashMap<K, V, Hash>::kDefaultConcurrencyLevel = 8;

template <class K, class V, class Hash>
const int ConcurrentHashMap<K, V, Hash>::kUndefinedSize = 64;
