#pragma once

#include <atomic>
#include <optional>
#include <stdexcept>
#include <utility>

template <class T>
class MPSCStack {
public:
    void Push(const T& value) {
        Node* new_node = new Node{value, head_.load()};
        while (!head_.compare_exchange_weak(new_node->parent_, new_node)) {
        }
    }

    std::optional<T> Pop() {
        if (!head_.load()) {
            return std::nullopt;
        }
        Node* to_delete = head_.load();
        while (!head_.compare_exchange_weak(to_delete, to_delete->parent_)) {
        }
        std::optional<T> answer = std::move(to_delete->value_);
        delete to_delete;
        return answer;
    }

    template <class TFn>
    void DequeueAll(const TFn& cb) {
        while (head_.load()) {
            cb(Pop().value());
        }
    }

    ~MPSCStack() {
        DequeueAll([](const T&) {});
    }

private:
    struct Node {
        T value_;
        Node* parent_ = nullptr;
    };
    std::atomic<Node*> head_{nullptr};
};
