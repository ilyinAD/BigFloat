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


BigFloat calculate_pi(int idx) {
    clock_t start, finish;
    start = clock();
    BigFloat Pi("0");
    BigInt deg_16("1");
    std::string prec = "0.";
    int idx1 = idx;
    while (idx1 > 0) {
        prec += '0';
        --idx1;
    }
    prec += '1';
    BigFloat prc(prec);
    BigFloat res = {"0"};
    BigFloat k("0");
    int cnt = 0;
    do  {
        res = (BigFloat("1") / deg_16);
        BigFloat res1 = (BigFloat("4") / (BigFloat("8") * k + BigFloat("1"))) - (BigFloat("2") / (BigFloat("8") * k + BigFloat("4"))) -
                        (BigFloat("1") / (BigFloat("8") * k + BigFloat("5"))) - (BigFloat("1") / (BigFloat("8") * k + BigFloat("6")));
        res = res * res1;
        Pi = Pi + res;
        deg_16 = deg_16 * BigInt("16");
        k = k + BigFloat("1");
        ++cnt;
    } while(res > prc);
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    std::cout << duration << ' '  << cnt << std::endl;
    return Pi;
}

int main() {

    show(calculate_pi(100));
    return 0;
}
