#pragma once

#include <utility>
#include <optional>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <stdexcept>

enum State { Unidentified, Sent, Received };

template <class T>
class UnbufferedChannel {
public:
    void Send(const T& value) {
        {
            std::unique_lock<std::mutex> lock(mutex_);
            undef_.wait(lock, [this]() -> bool {
                return stopped_.load() || state_ == State::Unidentified;
            });
            if (stopped_.load()) {
                throw std::runtime_error("Stopped.");
            }
            temp_ = std::move(value);
            state_ = State::Sent;
            sent_.notify_one();
            received_.wait(
                lock, [this]() -> bool { return stopped_.load() || state_ == State::Received; });
            if (stopped_.load() && state_ != Received) {
                throw std::runtime_error("Dont receive.");
            }
            state_ = State::Unidentified;
            temp_.reset();
        }
        undef_.notify_one();
    }

    std::optional<T> Recv() {
        std::optional<T> result;
        {
            std::unique_lock<std::mutex> lock(mutex_);
            sent_.wait(lock, [this]() -> bool { return stopped_.load() || state_ == State::Sent; });
            if (stopped_.load()) {
                return std::nullopt;
            }
            result = std::move(temp_);
            state_ = State::Received;
        }
        received_.notify_one();
        return result;
    }

    void Close() {
        stopped_ = true;
        sent_.notify_all();
        undef_.notify_all();
        received_.notify_all();
    }

private:
    State state_ = State::Unidentified;
    std::mutex mutex_;
    std::optional<T> temp_;
    std::atomic<bool> stopped_{false};
    std::condition_variable sent_;
    std::condition_variable undef_;
    std::condition_variable received_;
};
