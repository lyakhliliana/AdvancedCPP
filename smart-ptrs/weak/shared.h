#pragma once

#include "sw_fwd.h"  // Forward declaration

#include <cstddef>  // std::nullptr_t

template <typename T>
class SharedPtr {
public:
    ///////////// Constructors
    SharedPtr() noexcept : ptr_(nullptr), block_(nullptr) {
    }
    explicit SharedPtr(std::nullptr_t) noexcept : ptr_(nullptr), block_(nullptr) {
    }
    template <typename S>
    explicit SharedPtr(S* ptr) noexcept : ptr_(ptr), block_(new ControlBlockPointer<S>(ptr)) {
    }

    SharedPtr(T* ptr, ControlBlockBase* block) : ptr_(ptr), block_(block) {
    }
    SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), block_(other.block_) {
        if (block_) {
            block_->IncStrong();
        }
    }
    SharedPtr(SharedPtr&& other) : ptr_(std::move(other.ptr_)), block_(std::move(other.block_)) {
        other.block_ = nullptr;
        other.ptr_ = nullptr;
    }
    template <typename S>
    SharedPtr(const SharedPtr<S>& other) : ptr_(other.ptr_), block_(other.block_) {
        if (block_) {
            block_->IncStrong();
        }
    }
    template <typename S>
    SharedPtr(SharedPtr<S>&& other) : ptr_(std::move(other.ptr_)), block_(std::move(other.block_)) {
        other.block_ = nullptr;
        other.ptr_ = nullptr;
    }

    // Aliasing constructor
    template <typename Y>
    SharedPtr(const SharedPtr<Y>& other, T* ptr) : ptr_(ptr), block_(other.block_) {
        if (block_) {
            block_->IncStrong();
        }
    }

    // Promote `WeakPtr`
    explicit SharedPtr(const WeakPtr<T>& other) {
        if (other.Expired()) {
            throw BadWeakPtr();
        }
        ptr_ = other.ptr_;
        block_ = other.block_;
        block_->IncStrong();
    }
    //////////////// `operator=`-s

    SharedPtr& operator=(const SharedPtr& other) {
        if (block_ == other.block_) {
            return *this;
        }
        Reset();
        ptr_ = other.ptr_;
        block_ = other.block_;
        if (block_) {
            block_->IncStrong();
        }
        return *this;
    }

    SharedPtr& operator=(SharedPtr&& other) {
        if (block_ == other.block_) {
            return *this;
        }
        Swap(other);
        other.Reset();
        return *this;
    }

    ////////////// Destructor

    ~SharedPtr() {
        Reset();
    }

    ///////////////// Modifiers

    void Reset() {
        if (block_) {
            block_->DecStrong();
            if (block_->links_num == 0) {
                block_->ZeroStrong();
                if (block_->weak_count == 0) {
                    block_->ZeroWeak();
                }
            }
        }
        ptr_ = nullptr;
        block_ = nullptr;
    }

    template <typename U>
    void Reset(U* ptr) {
        Reset();
        ptr_ = ptr;
        block_ = new ControlBlockPointer<U>(ptr);
    }
    void Swap(SharedPtr& other) {
        std::swap(ptr_, other.ptr_);
        std::swap(block_, other.block_);
    }

    ///////////////// Observers

    T* Get() const {
        return ptr_;
    }
    T& operator*() const {
        return *ptr_;
    }
    T* operator->() const {
        return ptr_;
    }
    size_t UseCount() const {
        if (block_ == nullptr) {
            return 0;
        }
        return block_->links_num;
    }
    explicit operator bool() const {
        return ptr_ != nullptr && block_ != nullptr;
    }

    template <typename... Args>
    friend SharedPtr MakeShared(Args&&... args);

    friend class WeakPtr<T>;

    T* ptr_;
    ControlBlockBase* block_;
};

// Allocate memory only once
template <typename T, typename... Args>
SharedPtr<T> MakeShared(Args&&... args) {
    auto block = new ControlBlockEmplace<T>(std::forward<Args>(args)...);
    return SharedPtr<T>(block->GetStorage(), block);
}
// Look for usage examples in tests
// template <typename T>
// class EnableSharedFromThis {
// public:
//    SharedPtr<T> SharedFromThis();
//    SharedPtr<const T> SharedFromThis() const;
//
//    WeakPtr<T> WeakFromThis() noexcept;
//    WeakPtr<const T> WeakFromThis() const noexcept;
//};
