#pragma once
#include <memory>
#include <utility>

class Any {
private:
    struct BaseInner {
        using Ptr = std::unique_ptr<BaseInner>;
        virtual ~BaseInner() = default;
        virtual std::unique_ptr<BaseInner> Clone() = 0;
    };
    template <class T>
    struct Inner : public BaseInner {
        explicit Inner(T value) : value_(std::move(value)) {
        }
        std::unique_ptr<BaseInner> Clone() override {
            return std::make_unique<Inner<T>>(value_);
        }
        T value_;
    };

public:
    Any() {
    }

    template <class T>
    Any(const T& value) : ptr_(std::make_unique<Inner<T>>(value)) {
    }

    template <class T>
    Any& operator=(const T& value) {
        Any temp(value);
        Swap(temp);
        return *this;
    }

    Any(const Any& rhs) {
        if (rhs.ptr_) {
            ptr_ = rhs.ptr_->Clone();
        } else {
            ptr_ = nullptr;
        }
    }
    Any& operator=(const Any& rhs) {
        if (this == &rhs) {
            return *this;
        }
        Any temp(rhs);
        Swap(temp);
        return *this;
    }
    ~Any() {
    }

    bool Empty() const {
        return ptr_ == nullptr;
    }

    void Clear() {
        ptr_ = nullptr;
    }
    void Swap(Any& rhs) {
        std::swap(ptr_, rhs.ptr_);
    }

    template <class T>
    const T& GetValue() const {
        return dynamic_cast<const Inner<T>&>(*ptr_).value_;
    }

private:
    BaseInner::Ptr ptr_ = nullptr;
};
