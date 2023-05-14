#pragma once

#include <type_traits>
#include <utility>

template <typename T, bool V, bool = std::is_empty_v<T> && !std::is_final_v<T>>
struct Element;

template <typename T, bool V>
struct Element<T, V, true> : public T {
public:
    Element(){};

    Element(const T&){};

    Element(T&&){};

    T& Get() {
        return (*this);
    }

    const T& Get() const {
        return (*this);
    }
};

template <typename T, bool V>
struct Element<T, V, false> {
public:
    Element() : value_(T()){};

    Element(const T& val) : value_(val){};

    Element(T&& val) : value_(std::forward<T&&>(val)){};

    T& Get() {
        return value_;
    }

    const T& Get() const {
        return value_;
    }

private:
    T value_;
};
// V -- false - first_element, true - second_element
//  Me think, why waste time write lot code, when few code do trick.
template <typename F, typename S>
class CompressedPair : private Element<F, false>, private Element<S, true> {
public:
    CompressedPair() = default;

    CompressedPair(const F& first, const S& second)
        : Element<F, false>(first), Element<S, true>(second) {
    }

    CompressedPair(F&& first, S&& second)
        : Element<F, false>(std::forward<F>(first)), Element<S, true>(std::forward<S>(second)){};

    CompressedPair(const F& first, S&& second)
        : Element<F, false>(first), Element<S, true>(std::forward<S>(second)){};

    CompressedPair(F&& first, const S& second)
        : Element<F, false>(std::forward<F>(first)), Element<S, true>(second){};

    F& GetFirst() {
        return Element<F, false>::Get();
    }

    const F& GetFirst() const {
        return Element<F, false>::Get();
    }

    const S& GetSecond() const {
        return Element<S, true>::Get();
    }

    S& GetSecond() {
        return Element<S, true>::Get();
    }
};
