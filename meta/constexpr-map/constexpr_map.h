#pragma once

#include <stdexcept>
#include <utility>
#include <array>

template <class K, class V, int MaxSize = 8>
class ConstexprMap {
public:
    constexpr ConstexprMap() = default;

    constexpr V& operator[](const K& key) {
        if (cur_size_ == MaxSize && !Find(key)) {
            throw 0;
        }
        for (size_t i = 0; i < cur_size_; ++i) {
            if (map_[i].first == key) {
                return map_[i].second;
            }
        }
        map_[cur_size_].first = key;
        return map_[cur_size_++].second;
    }

    constexpr const V& operator[](const K& key) const {
        for (size_t i = 0; i < cur_size_; ++i) {
            if (map_[i].first == key) {
                return map_[i].second;
            }
        }
        throw 0;
    }

    constexpr bool Erase(const K& key) {
        size_t k = MaxSize;
        for (size_t i = 0; i < cur_size_; ++i) {
            if (map_[i].first == key) {
                k = i;
                break;
            }
        }
        if (k != MaxSize) {
            for (size_t i = k; i < cur_size_ - 1; ++i) {
                map_[i].first = map_[i + 1].first;
                map_[i].second = map_[i + 1].second;
            }
            --cur_size_;
            return true;
        }
        return false;
    }

    constexpr bool Find(const K& key) const {
        for (size_t i = 0; i < cur_size_; ++i) {
            if (map_[i].first == key) {
                return true;
            }
        }
        return false;
    }

    constexpr size_t Size() const {
        return cur_size_;
    }

    constexpr std::pair<K, V>& GetByIndex(size_t pos) {
        return map_[pos];
    }

    constexpr const std::pair<K, V>& GetByIndex(size_t pos) const {
        return map_[pos];
    }

private:
    size_t cur_size_ = 0;
    std::array<std::pair<K, V>, MaxSize> map_;
};
