#pragma once

#include <linux/futex.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <unistd.h>
#include <atomic>

// Atomically do the following:
//    if (*value == expected_value) {
//        sleep_on_address(value)
//    }
void FutexWait(int *value, int expected_value) {
    syscall(SYS_futex, value, FUTEX_WAIT_PRIVATE, expected_value, nullptr, nullptr, 0);
}

// Wakeup 'count' threads sleeping on address of value(-1 wakes all)
void FutexWake(int *value, int count) {
    syscall(SYS_futex, value, FUTEX_WAKE_PRIVATE, count, nullptr, nullptr, 0);
}

class Mutex {
public:
    void Lock() {
        int expected = 0;
        if (!value_.compare_exchange_strong(expected, 1)) {
            if (expected != 2) {
                expected = value_.exchange(2);
            }
            while (expected != 0) {
                FutexWait(reinterpret_cast<int *>(&value_), 2);
                expected = value_.exchange(2);
            }
        }
    }

    void Unlock() {
        if (value_.fetch_sub(1) != 1) {
            value_.exchange(0);
            FutexWake(reinterpret_cast<int *>(&value_), 1);
        }
    }

private:
    std::atomic<int> value_{0};
};
