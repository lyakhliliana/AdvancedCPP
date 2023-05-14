#pragma once

#include "constexpr_map.h"
#include <type_traits>

template <typename T>
constexpr void Swap(T& first, T& second) {
    T temp = std::move(first);
    first = std::move(second);
    second = std::move(temp);
}

template <class K, class V, int S>
constexpr auto Sort(ConstexprMap<K, V, S> map) {
    for (size_t i = 0; i < map.Size() - 1; ++i) {
        for (size_t j = 0; j < map.Size() - i - 1; ++j) {
            if constexpr (std::is_integral_v<K>) {
                if (map.GetByIndex(j + 1).first > map.GetByIndex(j).first) {
                    Swap(map.GetByIndex(j).first, map.GetByIndex(j + 1).first);
                    Swap(map.GetByIndex(j).second, map.GetByIndex(j + 1).second);
                }
            } else {
                if (map.GetByIndex(j + 1).first < map.GetByIndex(j).first) {
                    Swap(map.GetByIndex(j).first, map.GetByIndex(j + 1).first);
                    Swap(map.GetByIndex(j).second, map.GetByIndex(j + 1).second);
                }
            }
        }
    }
    return map;
}