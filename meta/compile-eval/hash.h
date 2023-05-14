#pragma once
constexpr int pow(int a, int b) { //NOLINT
    return (b > 0) ? static_cast<int>(a * pow(a, b - 1)) : 1;
}

constexpr int help_hash(const char *s, int p, int ind) { //NOLINT
    return *s * pow(p, ind) + (*s ? help_hash(s + 1, p, ind + 1) : 0);
}

constexpr int hash(const char *s, int p, int mod) { //NOLINT
    return help_hash(s, p, 0) % mod;
}
