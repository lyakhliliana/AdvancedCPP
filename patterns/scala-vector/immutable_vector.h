#pragma once
#include <vector>
#include <memory>

template <class T>
class ImmutableVector {
private:
    class Node {
    public:
        Node() : childs_(32) {
        }
        Node(const T& value) : value_(value) {
        }
        Node(T&& value) : value_(std::move(value)) {
        }
        Node([[maybe_unused]] const std::shared_ptr<Node>& other) : value_(other->GetValue()) {
            for ([[maybe_unused]] auto elem : other->childs_) {
                childs_.push_back(elem);
            }
        }
        void SetValue(const T& value) {
            value_ = value;
        }
        void SetValue(T&& val) {
            value_ = std::move(val);
        }
        std::shared_ptr<Node> GetChild(size_t index) {
            if (childs_[index]) {
                return childs_[index];
            }
            childs_[index] = std::make_shared<Node>();
            return childs_[index];
        }
        T& GetValue() {
            return value_;
        }

    public:
        T value_;
        std::vector<std::shared_ptr<Node>> childs_;
    };
    using PtrNode = std::shared_ptr<Node>;

public:
    ImmutableVector() : root_(std::make_shared<Node>()) {
    }

    explicit ImmutableVector(size_t count, const T& value = T()) {
        size_ = count;
        root_ = std::make_shared<Node>();
        for (size_t i = 0; i < size_; ++i) {
            Init(root_, i, value);
        }
    }

    template <typename Iterator>
    ImmutableVector(Iterator first, Iterator last) {
        root_ = std::make_shared<Node>();
        while (first != last) {
            Init(root_, size_, *first);
            ++first;
            ++size_;
        }
    }

    ImmutableVector([[maybe_unused]] std::initializer_list<T> l) {
        root_ = std::make_shared<Node>();
        for ([[maybe_unused]] auto& e : l) {
            Init(root_, size_, e);
            ++size_;
        }
    }
    ImmutableVector(const PtrNode root, size_t sz) : root_(root), size_(sz) {
    }

    ImmutableVector Set(size_t index, const T& value) {
        return ImmutableVector(Update(root_, index, value), size_);
    }

    const T& Get(size_t index) const {
        return GetValue(root_, index);
    }

    ImmutableVector PushBack(const T& value) {
        return ImmutableVector(Update(root_, size_, value), size_ + 1);
    }

    ImmutableVector PopBack() {
        return ImmutableVector(root_, size_ - 1);
    }

    size_t Size() const {
        return size_;
    }

private:
    template <typename U>
    void Init(const PtrNode& cur, size_t ind, U&& val) {
        if (ind) {
            Init(cur->GetChild(ind % 32), ind / 32, std::forward<U>(val));
        } else {
            cur->SetValue(std::forward<U>(val));
        }
    }

    const T& GetValue(const PtrNode& cur, size_t ind) const {
        if (ind) {
            return GetValue(cur->GetChild(ind % 32), ind / 32);
        }
        return cur->GetValue();
    }

    template <typename U>
    PtrNode Update(const PtrNode& cur, size_t ind, U&& val) {
        if (ind == 0) {
            PtrNode result = std::make_shared<Node>(cur);
            result->SetValue(std::forward<U>(val));
            return result;
        }
        PtrNode result = std::make_shared<Node>(cur);
        result->childs_[ind % 32] = Update(cur->GetChild(ind % 32), ind / 32, std::forward<U>(val));
        return result;
    }

private:
    size_t size_ = 0;
    PtrNode root_;
};
