#pragma once

#include <mutex>
#include <condition_variable>
#include <queue>

class DefaultCallback {
public:
    void operator()(int& value) {
        --value;
    }
};

class Semaphore {
public:
    Semaphore(int count) : count_(count) {
    }

    void Leave() {
        std::unique_lock<std::mutex> lock(mutex_);
        ++count_;
        if (!cv_.empty()) {
            cv_.front().notify_one();
        }
    }

    template <class Func>
    void Enter(Func callback) {
        std::unique_lock<std::mutex> lock(mutex_);
        int cur_time = time_enter_;
        ++time_enter_;
        cv_.emplace();
        cv_.back().wait(
            lock, [cur_time, this]() -> bool { return count_ > 0 && cur_time == time_exit_; });
        ++time_exit_;
        cv_.pop();
        callback(count_);
    }

    void Enter() {
        DefaultCallback callback;
        Enter(callback);
    }

private:
    std::mutex mutex_;
    std::queue<std::condition_variable> cv_;
    int count_ = 0;
    int time_enter_ = 0;
    int time_exit_ = 0;
};
