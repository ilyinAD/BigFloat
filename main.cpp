#include <iostream>
#include "bignum/BigInt.h"
#include "bignum/BigFloat.h"
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma optimize("Ofast")
#include <chrono>
//#include "gtest/gtest.h"



const BigFloat operator ""_bigfloat(const char *s) {
    return BigFloat(s);
}

void show(BigInt a) {
    if (a.sign == -1) {
        std::cout << '-';
    }
    for (int i = a.digit.size() - 1; i >= 0; --i) {
        std::cout << a.digit[i];
    }
    std::cout << std::endl;
}

void show(BigFloat a) {
    if (a.sign == -1) {
        std::cout << '-';
    }
    for (int i = a.digit.size() - 1; i >= 0; --i) {
        std::cout << a.digit[i];
        if (i == a.index) {
            std::cout << '.';
        }
    }
    std::cout << std::endl;
}




int main() {

    show(calculate_pi(100));
    return 0;
}
