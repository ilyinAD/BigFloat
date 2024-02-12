//
// Created by artem on 12.02.2024.
//

#include "BIgFloat.h"
#include "BIgInt.h"
#include <algorithm>
#define all(x) x.begin(), x.end()
using namespace mathclass;
BIgFloat::BIgFloat(const BIgFloat &num) {
    for (int i = 0; i < num.digit.size(); ++i) {
        digit.push_back(num.digit[i]);
    }
    sign = num.sign;
    index = num.index;
}

void BIgFloat::setBIgFloat(std::string s) {
    BIgFloat::index = 0;
    BIgFloat::sign = 1;
    if (s.size() == 0) {
        return;
    }
    int ind = 0;
    if (s[0] == '-') {
        BIgFloat::sign = -1;
        ++ind;
    }
    while (s[ind] == '0' && ind < s.size()) {
        ++ind;
    }
    if (ind == s.size()) {
        BIgFloat::sign = 1;
        return;
    }

    for (long long i = s.size() - 1; i >= ind; --i) {
        if (s[i] == '.') {
            BIgFloat::index = s.size() - 1 - i;
            continue;
        }
        BIgFloat::digit.push_back(s[i] - '0');
    }
    if (BIgFloat::index == BIgFloat::digit.size()) {
        BIgFloat::digit.push_back(0);
    }
}

const BIgFloat operator -(const BIgFloat& left) {
    BIgFloat num(left);
    num.sign *= -1;
    return num;
}

const BIgFloat operator +(BIgFloat& left) {
    BIgFloat num(left);
    return num;
}

const BIgFloat operator +(const BIgFloat& left, const BIgFloat& right) {
//    if (left.sign == -1) {
//        if (right.sign == -1) {
//            return -((-left) + (-right));
//        } else {
//            return right - (-left);
//        }
//    } else if (right.sign == -1){
//        return left - (-right);
//    }
//    if (left < right) {
//        return right + left;
//    }
    std::string sl;
    std::string sr;
    int i = std::max(left.index, right.index) - 1;
    while (i >= 0) {
        if (i >= left.index){
            sl += '0';
        } else {
            sl += (left.digit[left.index - i - 1] + '0');
        }
        if (i >= right.index){
            sr += '0';
        } else {
            sr += (right.digit[right.index - i - 1] + '0');
        }
        --i;
    }
    reverse(all(sl));
    reverse(all(sr));
    BIgInt fr1(sl);
    BIgInt fr2(sr);
    BIgInt add_fract = fr1 + fr2;
    std::string ans;
    for (int i = 0; i < std::max(sl.size(), sr.size()); ++i) {
        ans += (add_fract.digit[i] + '0');
    }
    int flag = 0;
    if (std::max(sl.size(), sr.size()) < add_fract.digit.size()) {
        flag = 1;
    }
    ans += '.';
    sl = "";
    sr = "";
    i = left.index;
    while (i < left.digit.size()) {
        sl += (left.digit[i] + '0');
        ++i;
    }
    i = right.index;
    while (i < right.digit.size()) {
        sr += (right.digit[i] + '0');
        ++i;
    }
    reverse(all(sl));
    reverse(all(sr));
    BIgInt in1(sl);
    BIgInt in2(sr);
    BIgInt add_in = in1 + in2;
    if (flag == 1)
        add_in = add_in + BIgInt("1");
    for (int i = 0; i < add_in.digit.size(); ++i) {
        ans += (add_in.digit[i] + '0');
    }
    reverse(all(ans));
    return BIgFloat(ans);
}