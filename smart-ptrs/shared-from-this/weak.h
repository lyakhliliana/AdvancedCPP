#pragma once

#include "sw_fwd.h"  // Forward declaration

// https://en.cppreference.com/w/cpp/memory/weak_ptr
template <typename T>
class WeakPtr {
public:
    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors

    WeakPtr() : ptr_(nullptr), block_(nullptr) {
    }

    WeakPtr(const WeakPtr& other) : ptr_(other.ptr_), block_(other.block_) {
        if (block_) {
            block_->IncWeak();
        }
    }

    template <typename S>
    WeakPtr(const WeakPtr<S>& other) : ptr_(other.ptr_), block_(other.block_) {
        if (block_) {
            block_->IncWeak();
        }
    }

    template <typename S>
    WeakPtr(WeakPtr<S>&& other) : ptr_(std::move(other.ptr_)), block_(std::move(other.block_)) {
        other.Reset();
    }

    // Demote `SharedPtr`
    // #2 from https://en.cppreference.com/w/cpp/memory/weak_ptr/weak_ptr
    WeakPtr(const SharedPtr<T>& other) : ptr_(other.ptr_), block_(other.block_) {
        if (block_) {
            block_->IncWeak();
        }
    }
    template <class S>
    WeakPtr(const SharedPtr<S>& other) : ptr_(other.ptr_), block_(other.block_) {
        if (block_) {
            block_->IncWeak();
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // `operator=`-s

    WeakPtr& operator=(const WeakPtr& other) {
        if (block_ == other.block_) {
            return *this;
        }
        ptr_ = other.ptr_;
        block_ = other.block_;
        if (block_) {
            block_->IncWeak();
        }
        return *this;
    }

    template <class S>
    WeakPtr& operator=(const WeakPtr<S>& other) {
        if (block_ == other.block_) {
            return *this;
        }
        ptr_ = other.ptr_;
        block_ = other.block_;
        if (block_) {
            block_->IncWeak();
        }
        return *this;
    }

    WeakPtr& operator=(WeakPtr&& other) {
        if (block_ == other.block_) {
            return *this;
        }
        Swap(other);
        other.Reset();
        return *this;
    }

    template <class S>
    WeakPtr& operator=(WeakPtr<S>&& other) {
        if (block_ == other.block_) {
            return *this;
        }
        Swap(other);
        other.Reset();
        return *this;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Destructor

    ~WeakPtr() {
        Reset();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Modifiers

    void Reset() {
        if (block_) {
            block_->DecWeak();
            if (block_->links_num == 0 && block_->weak_count == 0) {
                block_->ZeroWeak();
            }
            if constexpr (std::is_base_of_v<EnableSharedFromThisBase, T>) {
                if (block_->weak_count == 1 && block_->links_num == 0) {
                    block_->ZeroWeak();
                }
            }
        }
        ptr_ = nullptr;
        block_ = nullptr;
    }
    void Swap(WeakPtr& other) {
        std::swap(ptr_, other.ptr_);
        std::swap(block_, other.block_);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Observers

    size_t UseCount() const {
        return (!block_) ? 0 : block_->links_num;
    }
    bool Expired() const {
        return block_ == nullptr || block_->links_num == 0;
    }
    SharedPtr<T> Lock() const {
        return (block_ && block_->links_num) ? SharedPtr<T>(*this) : SharedPtr<T>();
    }

    T* ptr_;
    ControlBlockBase* block_;
    friend class EnableSharedFromThisBase;

    template <typename U>
    friend class EnableSharedFromThis;
};
