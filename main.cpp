#include <iostream>
#include "bignum/BIgInt.h"
#include "bignum/BIgFloat.h"
#include <algorithm>
#include <vector>
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
    BIgFloat Pi("0");
    while (Pi.index < idx) {

    }
}

int main() {
//    BIgInt obj2("2");
//    BIgInt obj1("15");
//    BIgInt obj3("-19999");
//    BIgInt obj4("2434");
//    BIgInt obj5("0");
//    BIgInt obj6("111111");
    //show(obj3 * obj4);
//    BIgInt obj7("0");
    std::cout << (12.12_bigfloat).index;
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
