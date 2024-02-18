#include <iostream>
#include "bignum/BigInt.h"
#include "bignum/BigFloat.h"
#include <algorithm>
#include <vector>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma optimize("Ofast")

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

#include <chrono>

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
//    BigFloat o1("12.3000");
//    BigFloat o2("5");
//    BigFloat o3("0");
//    BigFloat o4("13");
//    BigFloat o5("3");
//    show(o1 * o2);
//    show(o1 + o2);
//    show(o3 * o4);
//    show(o3 / o2);
//    show(o2 / o5);
//    show(o5 - o1);
//    BigInt o1("12");
//    BigInt o2("0");
//    BigInt o3("20");
//    BigInt o4("1");
//    BigInt o5("-1003221");
//    show(o1 * o2);
//    show(o1 + o2);
//    show(o3 * o4);
//    show(o2 / o3);
//    show(o5 / o3);
//    show(o5 - o1);
    show(calculate_pi(100));
    //show(12323.2323_bigfloat);
    //    BigFloat o1("12.3000");
//    BigFloat o2("5");
//    BigFloat o3("0");
//    BigFloat o4("13");
//    BigFloat o5("3");
//    show(o1 * o2);
//    show(o1 + o2);
//    show(o3 * o4);
//    show(o3 / o2);
//    show(o2 / o5);
//    show(o5 - o1);
//    BigInt o1("12");
//    BigInt o2("0");
//    BigInt o3("20");
//    BigInt o4("1");
//    BigInt o5("-1003221");
//    show(o1 * o2);
//    show(o1 + o2);
//    show(o3 * o4);
//    show(o2 / o3);
//    show(o5 / o3);
//    show(o5 - o1);
    return 0;
}
