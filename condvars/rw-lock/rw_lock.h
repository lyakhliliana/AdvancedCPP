#pragma once
#include <mutex>
#include <condition_variable>

class RWLock {
public:
    template <class Func>
    void Read(Func func) {
        mutex_.lock();
        ++blocked_readers_;
        mutex_.unlock();
        try {
            func();
        } catch (...) {
            EndRead();
            throw;
        }
        EndRead();
    }

    template <class Func>
    void Write(Func func) {
        std::unique_lock<std::mutex> lock(mutex_);
        cv_.wait(lock, [this]() -> bool { return blocked_readers_ == 0; });
        func();
    }

private:
    std::mutex mutex_;
    std::condition_variable cv_;
    int blocked_readers_ = 0;

private:
    void EndRead() {
        mutex_.lock();
        --blocked_readers_;
        cv_.notify_all();
        mutex_.unlock();
    }
};
