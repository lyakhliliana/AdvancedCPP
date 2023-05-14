#pragma once

#include <utility>
#include <optional>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <atomic>

template <class T>
class BufferedChannel {
public:
    explicit BufferedChannel(int size) : size_(size) {
    }

    void Send(const T& value) {
        {
            std::unique_lock<std::mutex> lock(mutex_);
            not_over_.wait(lock, [this]() { return stopped_ || buffer_.size() != size_; });
            if (stopped_) {
                throw std::runtime_error("Stopped.");
            }
            buffer_.push_back(value);
        }
        not_empty_.notify_one();
    }

    std::optional<T> Recv() {
        T result;
        {
            std::unique_lock<std::mutex> lock(mutex_);
            not_empty_.wait(lock, [this]() { return stopped_ || !buffer_.empty(); });
            if (buffer_.empty()) {
                return std::nullopt;
            }
            result = std::move(buffer_.front());
            buffer_.pop_front();
        }
        not_over_.notify_one();
        return result;
    }

    void Close() {
        stopped_ = true;
        not_empty_.notify_all();
        not_over_.notify_all();
    }

private:
    std::atomic<bool> stopped_{false};
    std::size_t size_;
    std::mutex mutex_;
    std::condition_variable not_empty_;
    std::condition_variable not_over_;
    std::deque<T> buffer_;
};
