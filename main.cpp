#include <iostream>
#include "bignum/BIgInt.h"
#include "bignum/BIgFloat.h"
#include <algorithm>
#include <vector>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma optimize("Ofast")
using namespace mathclass;

void show(BIgInt a) {
    if (a.digit.size() == 0) {
        std::cout << 0 << std::endl;
        return;
    }
    if (a.sign == -1) {
        std::cout << '-';
    }
    for (int i = a.digit.size() - 1; i >= 0; --i) {
        std::cout << a.digit[i];
    }
    std::cout << std::endl;
}

void show(BIgFloat a) {
    if (a.digit.size() == 0) {
        std::cout << 0 << std::endl;
        return;
    }
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
namespace std::chrono_literals {
    const BIgFloat operator ""_bigfloat(const char *s) {
        return BIgFloat(s);
    }
}
using std::chrono_literals::operator""_bigfloat;

BIgFloat pi(int idx) {
    clock_t start, finish;
    start = clock();
    if (idx == 0) {
        return BIgFloat("3");
    }
    BIgFloat Pi("0");
    BIgInt deg_16("1");
    std::string prec = "0.";
    int idx1 = idx;
    while (idx1 > 1) {
        prec += '0';
        --idx1;
    }
    prec += '1';
    BIgFloat prc(prec);
    BIgFloat res = {"0"};
    BIgFloat k("0");
    do  {
        res = (BIgFloat("1") / deg_16);
        BIgFloat res1 = (BIgFloat("4") / (BIgFloat("8") * k + BIgFloat("1"))) - (BIgFloat("2") / (BIgFloat("8") * k + BIgFloat("4"))) -
        (BIgFloat("1") / (BIgFloat("8") * k + BIgFloat("5"))) - (BIgFloat("1") / (BIgFloat("8") * k + BIgFloat("6")));
        res = res * res1;
        Pi = Pi + res;
        deg_16 = deg_16 * BIgInt("16");
        k = k + BIgFloat("1");
    } while(res > prc);
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    std::cout << duration << std::endl;
    return Pi;
}

int main() {
    show(pi(100));
//    BIgInt obj2("2");
//    BIgInt obj1("15");
//    BIgInt obj3("-19999");
//    BIgInt obj4("2434");
//    BIgInt obj5("0");
//    BIgInt obj6("111111");
    //show(obj3 * obj4);
//    BIgInt obj7("0");
    //show(12.12_bigfloat / 0.234_bigfloat);
//    BIgFloat o1("5");
//    BIgFloat o2("2");
//    BIgFloat o3("-1257495374598759.997535438543759435345984375349543857845734581111111111111111111111111111111111111111111111111111111111111");
//    BIgFloat o4("-4723472342947238479324782.4927439874294732473284732473847239472111111111111111111111111111111111111111111111111111111111");
//    show(o3 * o4);
//    std::cout << (o3 < o4) << std::endl;
    //show(obj3 / obj4);
    //show(o4 / o3);
//    show(o2+o4);
//    show(o1-o2);
//    show(o1-o3);
    //std::cout << (o3 < o4) << ' ' << (o3 == o4) << ' ' << (o1 >= o1) << ' ' << (o3 < o4) << ' ' << (o1 < o2);
//    show(o2);
//    show(o3);
//    show(o4);
//    int a[4] = {1, 9, 9, 0};
//    int b[4] = {1, 0, 4, 0};
//    int c[8] = {0, 0, 0, 0, 0, 0, 0, 0};
//    karatsuba(a, b, c, 4);
    return 0;
}
