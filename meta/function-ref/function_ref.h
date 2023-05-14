#pragma once

#include <utility>
#include <functional>
#include <memory>
#include <type_traits>

template <typename Signature>
class FunctionRef;

template <typename Result, typename... Args>
class FunctionRef<Result(Args...)> {
public:
    template <typename T>
    FunctionRef(T&& functor) noexcept : functor_(reinterpret_cast<void*>(&functor)) {
        erased_ = [](void* ptr, Args&&... args) -> Result {
            if constexpr (!std::is_void_v<Result>) {
                return (*reinterpret_cast<typename std::add_pointer<T>::type>(ptr))(
                    std::forward<Args>(args)...);
            }
            (*reinterpret_cast<typename std::add_pointer<T>::type>(ptr))(
                std::forward<Args>(args)...);
        };
    }

    decltype(auto) operator()(Args&&... args) const {
        if constexpr (!std::is_void_v<Result>) {
            return erased_(functor_, std::forward<Args>(args)...);
        }
        erased_(functor_, std::forward<Args>(args)...);
    }

private:
    void* functor_ = nullptr;
    Result (*erased_)(void*, Args&&...) = nullptr;
};
