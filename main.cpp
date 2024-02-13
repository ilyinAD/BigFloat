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
//        std::string str;
//        while ((*s) != '\0') {
//            str += s;
//            ++s;
//        }
        return BIgFloat(s);
    }
}
using std::chrono_literals::operator""_bigfloat;

int main() {
    BIgInt obj2("2");
    BIgInt obj1("15");
    BIgInt obj3("-19999");
    BIgInt obj4("2434");
    BIgInt obj5("0");
    BIgInt obj6("111111");
    //show(obj3 * obj4);
//    BIgInt obj7("0");
//    BIgFloat o1("5");
//    BIgFloat o2("2");
//    BIgFloat o3("12.99");
//    BIgFloat o4("13.01");
//    std::cout << (o3 < o4) << std::endl;
    //show(obj3 / obj4);
    show(-12.12_bigfloat);
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
