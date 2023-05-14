#pragma once

#include "compressed_pair.h"

#include <cstddef>  // std::nullptr_t

struct Slug {
    template <typename T>
    void operator()(T* ptr) {
        delete ptr;
    }
};

// Primary template
template <typename T, typename Deleter = Slug>
class UniquePtr {
public:
    /////////////// Constructors

    explicit UniquePtr(T* ptr = nullptr) {
        ptr_.GetFirst() = ptr;
    }
    UniquePtr(T* ptr, typename std::decay<Deleter>::type& deleter) {
        ptr_.GetFirst() = ptr;
        ptr_.GetSecond() = deleter;
    }
    UniquePtr(T* ptr, const typename std::decay<Deleter>::type& deleter) {
        ptr_.GetFirst() = ptr;
        ptr_.GetSecond() = deleter;
    }
    UniquePtr(T* ptr, typename std::decay<Deleter>::type&& deleter) {
        ptr_.GetFirst() = ptr;
        ptr_.GetSecond() = std::forward<Deleter>(deleter);
    }

    template <typename S, typename Del>
    UniquePtr(UniquePtr<S, Del>&& other) noexcept {
        ptr_.GetFirst() = other.Release();
        ptr_.GetSecond() = std::forward<Deleter>(other.GetDeleter());
    }

    UniquePtr(UniquePtr& other) = delete;

    ////////////// `operator=`-s

    UniquePtr& operator=(UniquePtr&& other) noexcept {
        Reset(other.Release());
        ptr_.GetSecond() = std::forward<Deleter>(other.ptr_.GetSecond());
        return *this;
    }
    UniquePtr& operator=(std::nullptr_t) noexcept {
        Reset(nullptr);
        return *this;
    }

    ///////////////// Destructor

    ~UniquePtr() noexcept {
        if (ptr_.GetFirst()) {
            ptr_.GetSecond()(ptr_.GetFirst());
        }
    }

    ////////////////  Modifiers

    T* Release() {
        T* temp = ptr_.GetFirst();
        ptr_.GetFirst() = nullptr;
        return temp;
    }

    void Reset(T* ptr = nullptr) noexcept {
        if (ptr_.GetFirst() == ptr) {
            return;
        }
        T* temp = ptr_.GetFirst();
        ptr_.GetFirst() = ptr;
        if (temp) {
            ptr_.GetSecond()(temp);
        }
    }

    void Swap(UniquePtr& other) noexcept {
        if (ptr_.GetFirst() != other.ptr_.GetFirst()) {
            std::swap(ptr_, other.ptr_);
        }
    }

    //////////////// Observers

    T* Get() const noexcept {
        return ptr_.GetFirst();
    }
    Deleter& GetDeleter() {
        return ptr_.GetSecond();
    }
    const Deleter& GetDeleter() const {
        return ptr_.GetSecond();
    }
    explicit operator bool() const noexcept {
        return ptr_.GetFirst() != nullptr;
    }

    ////////////// Single-object dereference operators

    typename std::add_lvalue_reference<T>::type operator*() const noexcept {
        return *ptr_.GetFirst();
    }

    T* operator->() const noexcept {
        return ptr_.GetFirst();
    }

private:
    CompressedPair<T*, Deleter> ptr_;
};

// Specialization for arrays
template <typename T, typename Deleter>
class UniquePtr<T[], Deleter> {
public:
    explicit UniquePtr(T* ptr = nullptr) {
        ptr_.GetFirst() = ptr;
    }
    UniquePtr(T* ptr, typename std::decay<Deleter>::type& deleter) {
        ptr_.GetFirst() = ptr;
        ptr_.GetSecond() = deleter;
    }
    UniquePtr(T* ptr, const typename std::decay<Deleter>::type& deleter) {
        ptr_.GetFirst() = ptr;
        ptr_.GetSecond() = deleter;
    }
    UniquePtr(T* ptr, typename std::decay<Deleter>::type&& deleter) {
        ptr_.GetFirst() = ptr;
        ptr_.GetSecond() = std::forward<Deleter>(deleter);
    }

    UniquePtr(UniquePtr& other) = delete;

    ~UniquePtr() noexcept {
        if (ptr_.GetFirst()) {
            delete[] ptr_.GetFirst();
        }
    }
    void Reset(T* ptr = nullptr) noexcept {
        if (ptr_.GetFirst() == ptr) {
            return;
        }
        T* temp = ptr_.GetFirst();
        ptr_.GetFirst() = ptr;
        if (temp) {
            delete[] temp;
        }
    }
    T& operator[](size_t i) const {
        return ptr_.GetFirst()[i];
    }

private:
    CompressedPair<T*, Deleter> ptr_;
};
