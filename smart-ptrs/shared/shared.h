#pragma once

#include "sw_fwd.h"  // Forward declaration

#include <cstddef>  // std::nullptr_t
class ControlBlockBase {
public:
    virtual ~ControlBlockBase() = default;
    void Inc() {
        ++links_num;
    }
    void Dec() {
        --links_num;
    }

public:
    size_t links_num = 1;
};

template <typename U>
class ControlBlockPointer : public ControlBlockBase {
public:
    ControlBlockPointer(U* ptr) : ptr_(ptr) {
    }
    ~ControlBlockPointer() override {
        delete ptr_;
    }

public:
    U* ptr_;
};

template <typename U>
class ControlBlockEmplace : public ControlBlockBase {
public:
    template <typename... Args>
    ControlBlockEmplace(Args&&... args) {
        new (&storage_) U{std::forward<Args>(args)...};
    }

    U* GetStorage() {
        return reinterpret_cast<U*>(&storage_);
    }

    ~ControlBlockEmplace() override {
        GetStorage()->~U();
    }

public:
    std::aligned_storage_t<sizeof(U), alignof(U)> storage_;
};

template <typename T>
class SharedPtr {
public:
    ///////////// Constructors

    SharedPtr() : ptr_(nullptr), block_(nullptr) {
    }
    explicit SharedPtr(std::nullptr_t) : ptr_(nullptr), block_(nullptr) {
    }

    explicit SharedPtr(T* ptr) : ptr_(ptr), block_(new ControlBlockPointer<T>(ptr)) {
    }

    template <typename S>
    explicit SharedPtr(S* ptr) : ptr_(ptr), block_(new ControlBlockPointer<S>(ptr)) {
    }

    SharedPtr(T* ptr, ControlBlockBase* block) : ptr_(ptr), block_(block) {
    }
    SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), block_(other.block_) {
        if (block_) {
            block_->Inc();
        }
    }
    SharedPtr(SharedPtr&& other) : ptr_(std::move(other.ptr_)), block_(std::move(other.block_)) {
        other.block_ = nullptr;
        other.ptr_ = nullptr;
    }
    template <typename S>
    SharedPtr(const SharedPtr<S>& other) : ptr_(other.ptr_), block_(other.block_) {
        if (block_) {
            block_->Inc();
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
        block_->Inc();
    }

    // Promote `WeakPtr`
    //    explicit SharedPtr(const WeakPtr<T>& other): ptr_(other.ptr_), block_(other.block_){
    //        if (other.Ex()){
    //            throw BadWeakPtr();
    //        }
    //        block_->Inc();
    //    }
    //////////////// `operator=`-s

    SharedPtr& operator=(const SharedPtr& other) {
        if (this == &other) {
            return *this;
        }
        if (block_ != nullptr) {
            block_->Dec();
            if (block_->links_num == 0) {
                delete block_;
                ptr_ = nullptr;
            }
        }
        ptr_ = other.ptr_;
        block_ = other.block_;
        if (block_) {
            block_->Inc();
        }
        return *this;
    }

    SharedPtr& operator=(SharedPtr&& other) {
        if (this == &other) {
            return *this;
        }
        if (block_ != nullptr) {
            block_->Dec();
            if (block_->links_num == 0) {
                delete block_;
                ptr_ = nullptr;
            }
        }
        ptr_ = other.ptr_;
        block_ = other.block_;
        other.ptr_ = nullptr;
        other.block_ = nullptr;
        return *this;
    }

    ////////////// Destructor

    ~SharedPtr() {
        if (block_ != nullptr) {
            block_->Dec();
            if (block_->links_num == 0) {
                delete block_;
                ptr_ = nullptr;
            }
        }
    }

    ///////////////// Modifiers

    void Reset() {
        if (block_) {
            block_->Dec();
            if (block_->links_num == 0) {
                delete block_;
                ptr_ = nullptr;
                block_ = nullptr;
            }
        }
    }
    void Reset(T* ptr) {
        if (block_) {
            block_->Dec();
            if (block_->links_num == 0) {
                delete block_;
            }
        }
        ptr_ = ptr;
        block_ = new ControlBlockPointer(ptr);
    }
    template <typename U>
    void Reset(U* ptr) {
        if (block_) {
            block_->Dec();
            if (block_->links_num == 0) {
                delete block_;
            }
        }
        ptr_ = ptr;
        block_ = new ControlBlockPointer(ptr);
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
        return ptr_ != nullptr;
    }

    template <typename... Args>
    friend SharedPtr MakeShared(Args&&... args);

    T* ptr_;
    ControlBlockBase* block_;
};

// Allocate memory only once
template <typename T, typename... Args>
SharedPtr<T> MakeShared(Args&&... args) {
    auto block = new ControlBlockEmplace<T>(std::forward<Args>(args)...);
    return SharedPtr<T>(block->GetStorage(), block);
}

// template <typename T, typename U>
// inline bool operator==(const SharedPtr<T>& left, const SharedPtr<U>& right);

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
