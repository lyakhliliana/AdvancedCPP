#pragma once

#include <atomic>
#include <cstdint>

struct RWSpinLock {
public:
    void LockRead() {
        uint64_t expected = users_.load();
        do {
            while (expected & 1) {
                expected = users_.load();
            }
        } while (!users_.compare_exchange_weak(expected, expected + 2));
    }

    void UnlockRead() {
        users_.fetch_sub(2);
    }

    void LockWrite() {
        uint64_t expected = users_.load();
        do {
            while (expected != 0) {
                expected = users_.load();
            }
        } while (!users_.compare_exchange_weak(expected, expected + 1));
    }

    void UnlockWrite() {
        users_.fetch_sub(1);
    }

private:
    std::atomic<uint64_t> users_{0};
};
