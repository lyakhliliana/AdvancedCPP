#pragma once
#include <memory>
#include <exception>
class ControlBlockBase {
public:
    virtual ~ControlBlockBase() = default;
    virtual void ZeroStrong() = 0;
    virtual void ZeroWeak() = 0;
    void IncStrong() {
        ++links_num;
    }
    void DecStrong() {
        --links_num;
    }
    void IncWeak() {
        ++weak_count;
    }
    void DecWeak() {
        --weak_count;
    }

public:
    size_t links_num = 1;
    size_t weak_count = 0;
};

template <typename U>
class ControlBlockPointer : public ControlBlockBase {
public:
    ControlBlockPointer(U* ptr) : ptr_(ptr) {
    }
    ~ControlBlockPointer() override = default;
    void ZeroStrong() override {
        if (ptr_) {
            delete ptr_;
            ptr_ = nullptr;
        }
    }
    void ZeroWeak() override {
        delete this;
    }

public:
    U* ptr_ = nullptr;
};

template <typename U>
class ControlBlockEmplace : public ControlBlockBase {
public:
    template <typename... Args>
    ControlBlockEmplace(Args&&... args) {
        new (&storage_) U{std::forward<Args>(args)...};
    }

    ~ControlBlockEmplace() override = default;

    U* GetStorage() {
        return reinterpret_cast<U*>(&storage_);
    }

    void ZeroStrong() override {
        std::destroy_at(std::launder(reinterpret_cast<U*>(&storage_)));
    }

    void ZeroWeak() override {
        delete this;
    }

public:
    std::aligned_storage_t<sizeof(U), alignof(U)> storage_;
};

// Instead of std::bad_weak_ptr
class BadWeakPtr : public std::exception {};

template <typename T>
class SharedPtr;

template <typename T>
class WeakPtr;

class EnableSharedFromThisBase {
public:
    virtual ~EnableSharedFromThisBase() {
    }
};

template <typename T>
class EnableSharedFromThis;