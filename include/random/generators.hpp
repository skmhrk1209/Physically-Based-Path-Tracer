#pragma once
#include <cstdint>
#include <iostream>

namespace coex::random {

template <typename T = std::int_fast32_t, T A = 48271, T B = 0, T M = 2147483647>
struct LinearCongruentialGenerator {
    static constexpr T a = A;
    static constexpr T b = B;
    static constexpr T m = M;
    static constexpr T min = 0;
    static constexpr T max = M;

    constexpr LinearCongruentialGenerator() = default;
    constexpr LinearCongruentialGenerator(T seed) : x(seed){};

    constexpr T operator()() {
        // Stephen K. Park & Keith W. Miller
        // https://c-faq.com/lib/rand.html
        x = a * (x % q) - r * (x / q);
        x = x > 0 ? x : x + m;
        return x;
    }

private:

    static constexpr T q = M / A;
    static constexpr T r = M % A;

    T x;
};

}  // namespace coex::random
