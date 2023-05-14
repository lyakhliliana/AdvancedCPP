#pragma once

#include <mutex>
#include <condition_variable>
#include <chrono>
#include <map>
#include <set>
#include <thread>

template <class T>
class TimerQueue {
public:
    using Clock = std::chrono::system_clock;
    using TimePoint = Clock::time_point;

public:
    void Add(const T& item, TimePoint at) {
        std::unique_lock<std::mutex> lock(mutex_);
        if (buf_.empty()) {
            buf_.insert({at, item});
            not_empty_.notify_all();
        } else {
            if ((*buf_.begin()).first > at) {
                buf_.insert({at, item});
                to_wait_.notify_one();
            } else {
                buf_.insert({at, item});
            }
        }
    }

    T Pop() {
        std::unique_lock<std::mutex> lock(mutex_);
        not_empty_.wait(lock, [this]() -> bool { return buf_.size() > 0; });
        while ((*buf_.begin()).first > Clock::now()) {
            to_wait_.wait_until(lock, (*buf_.begin()).first);
        }
        auto pair = *buf_.begin();
        buf_.erase(buf_.begin());
        return pair.second;
    }

private:
    std::mutex mutex_;
    std::condition_variable not_empty_;
    std::condition_variable to_wait_;
    std::multiset<std::pair<TimePoint, T>> buf_;
};
