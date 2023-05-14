#pragma once

template <unsigned a, unsigned b>
struct Pow {
    static const unsigned Value = a * Pow<a, b - 1>::value; //NOLINT
};
template <unsigned a>
struct Pow<a, 0> {
    static const unsigned value = 1; //NOLINT
};
