#include <iostream>
#include "bignum/BIgInt.h"
#include "bignum/BIgFloat.h"
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

int main() {
    BIgInt obj2("1");
    BIgInt obj1("12");
    BIgInt obj3("19999");
    BIgInt obj4("-2434");
    BIgInt obj5("0");
        BIgInt obj6("111111");
    BIgInt obj7("8678");
    BIgFloat o1("123");
    BIgFloat o2("12.34224424");
    BIgFloat o3("9795374.342545424");
    BIgFloat o4("11450.13535345349594");
    show(o4+o3);
//    show(o2);
//    show(o3);
//    show(o4);
    return 0;
}
