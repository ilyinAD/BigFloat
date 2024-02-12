#include <iostream>
#include "BIgInt.h"
#include "BIgFloat.h"
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

int main() {
    BIgInt obj2("1");
    BIgInt obj1("12");
    BIgInt obj3("19999");
    BIgInt obj4("-2434");
    BIgInt obj5("0");
        BIgInt obj6("111111");
    BIgInt obj7("8678");
    show(obj6);
    show(obj7);
    show(obj6 - obj7);
    return 0;
}
