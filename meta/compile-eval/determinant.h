#pragma once

#include <array>

template <int N>
constexpr std::array<std::array<int, N - 1>, N - 1> GetSub(
    const std::array<std::array<int, N>, N>& a, int m, int n) {
    std::array<std::array<int, N - 1>, N - 1> new_a;
    for (size_t i = 0; i < N - 1; ++i) {
        for (size_t j = 0; j < N - 1; ++j) {
            new_a[i][j] = a[i + (i >= m ? 1 : 0)][j + (j >= n ? 1 : 0)];
        }
    }
    return new_a;
}

template <int N>
constexpr int determinant(const std::array<std::array<int, N>, N>& a) { //NOLINT
    int det_agg = 0;
    for (int row = 0; row < N; ++row) {
        det_agg += (row % 2 == 0 ? 1 : -1) * a[row][0] * determinant<N - 1>(GetSub<N>(a, row, 0));
    }
    return det_agg;
}

template <>
constexpr int determinant<1>(const std::array<std::array<int, 1>, 1>& a) {
    return a[0][0];
}