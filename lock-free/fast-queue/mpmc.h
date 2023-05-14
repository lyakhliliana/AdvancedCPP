#pragma once

#include <atomic>
#include <vector>

template <class T>
class MPMCBoundedQueue {
public:
    explicit MPMCBoundedQueue(size_t size) : queue_(size) {
        max_size_ = size;
        for (size_t i = 0; i < max_size_; ++i) {
            queue_[i].generation.store(i);
        }
    }

    bool Enqueue(const T& value) {
        if (tail_.load() - head_.load() == max_size_) {
            return false;
        }
        size_t expected = tail_.load();
        do {
            expected = tail_.load();
            if (queue_[tail_.load() & (max_size_ - 1)].generation < expected) {
                return false;
            }
        } while (!tail_.compare_exchange_weak(expected, expected + 1));
        queue_[expected & (max_size_ - 1)].value = std::move(value);
        queue_[expected & (max_size_ - 1)].generation.fetch_add(1);
        return true;
    }

    bool Dequeue(T& data) {
        if (tail_.load() - head_.load() == 0) {
            return false;
        }
        size_t expected = head_.load();
        do {
            expected = head_.load();
            if (queue_[head_.load() & (max_size_ - 1)].generation < expected + 1) {
                return false;
            }
        } while (!head_.compare_exchange_weak(expected, expected + 1));
        data = std::move(queue_[expected & (max_size_ - 1)].value);
        queue_[expected & (max_size_ - 1)].generation = expected + max_size_;
        return true;
    }

private:
    struct Node {
        T value{};
        std::atomic<size_t> generation{0};
    };
    std::vector<Node> queue_;
    size_t max_size_{0};
    std::atomic<size_t> head_{0}, tail_{0};
};
