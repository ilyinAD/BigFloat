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

BIgFloat::BIgFloat(const mathclass::BIgInt &num) {
    for (int i = 0; i < num.digit.size(); ++i) {
        digit.push_back(num.digit[i]);
    }
    sign = num.sign;
    index = 0;
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

void BIgFloat::delete_leadings_zeroes() {
    std::vector<int> v = BIgFloat::digit;
    int cnt = 0;
    while (BIgFloat::index > 0 && BIgFloat::digit[cnt] == 0) {
        --BIgFloat::index;
        ++cnt;
    }
    BIgFloat::digit.clear();
    for (int i = cnt; i < v.size(); ++i) {
        BIgFloat::digit.push_back(v[i]);
    }
}

bool operator ==(const BIgFloat& left, const BIgFloat& right) {
    if (left.sign != right.sign || right.digit.size() != left.digit.size()) {
        return false;
    }
    if (left.index != right.index) {
        return false;
    }
    for (int i = 0; i < left.digit.size(); ++i) {
        if (left.digit[i] != right.digit[i]) {
            return false;
        }
    }
    return true;
}

bool operator <(const BIgFloat& left, const BIgFloat& right) {
    if (left == right) {
        return false;
    }
    if (left.sign != right.sign) {
        return left.sign < right.sign;
    }
    if ((right.digit.size() - right.index) != (left.digit.size() - left.index)) {
        return (left.digit.size() - left.index) < (right.digit.size() - right.index);
    }
    int i = left.digit.size() - 1;
    int j = right.digit.size() - 1;
    while (i != -1 && j != -1) {
        int val1 = 0;
        if (i != -1) {
            val1 = left.digit[i];
            --i;
        }
        int val2 = 0;
        if (j != -1) {
            val2 = right.digit[j];
            --j;
        }
        if (val1 < val2) {
            return true;
        } else if (val2 < val1) {
            return false;
        }
    }
    std::cout << "WRONG" << std::endl;
}

bool operator <=(const BIgFloat& left, const BIgFloat& right) {
    return (left < right || left == right);
}

bool operator >=(const BIgFloat& left, const BIgFloat& right) {
    return !(left < right);
}

bool operator >(const BIgFloat& left, const BIgFloat& right) {
    return !(left <= right);
}

bool operator !=(const BIgFloat& left, const BIgFloat& right) {
    return !(left == right);
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

std::string get_str(const BIgFloat& num) {
    std::string sl;
    if (num.sign == -1) {
        sl += '-';
    }
    for (int i = num.digit.size() - 1; i >= 0; --i) {
        sl += (num.digit[i] + '0');
    }
    return sl;
}

const BIgFloat operator +(const BIgFloat& left, const BIgFloat& right) {
    if (left.sign == -1) {
        if (right.sign == -1) {
            return -((-left) + (-right));
        } else {
            return right - (-left);
        }
    } else if (right.sign == -1){
        return left - (-right);
    }
    if (left < right) {
        return right + left;
    }
    std::string sl = get_str(left);
    std::string sr = get_str(right);
    int i = 0;
    while (left.index + i < right.index) {
        sl += '0';
        ++i;
    }
    i = 0;
    while (right.index + i < left.index) {
        sr += '0';
        ++i;
    }
    BIgInt in1(sl);
    BIgInt in2(sr);
    BIgInt add = in1 + in2;
    BIgFloat add_ans(add);
    add_ans.index = std::max(left.index, right.index);
    if (add_ans.index == add_ans.digit.size()) {
        add_ans.digit.push_back(0);
    }
    add_ans.delete_leadings_zeroes();
    return add_ans;

}

const BIgFloat operator -(const BIgFloat& left, const BIgFloat& right) {
    if (left.sign == 1) {
        if (right.sign == -1) {
            return left + (-right);
        }
    } else {
        if (right.sign == 1) {
            return -((-left) + (right));
        } else {
            return (-right) - (-left);
        }
    }
    if (left < right) {
        return -(right - left);
    }
    std::string sl = get_str(left);
    std::string sr = get_str(right);
    int i = 0;
    while (left.index + i < right.index) {
        sl += '0';
        ++i;
    }
    i = 0;
    while (right.index + i < left.index) {
        sr += '0';
        ++i;
    }
    BIgInt in1(sl);
    BIgInt in2(sr);
    BIgInt sub = in1 - in2;
    BIgFloat sub_ans(sub);
    sub_ans.index = std::max(left.index, right.index);
    if (sub_ans.index == sub_ans.digit.size()) {
        sub_ans.digit.push_back(0);
    }
    sub_ans.delete_leadings_zeroes();
    return sub_ans;
}

const BIgFloat operator *(const BIgFloat& left, const BIgFloat& right) {
    std::string sl = get_str(left);
    std::string sr = get_str(right);
    BIgInt left1(sl);
    BIgInt right1(sr);
    BIgInt mul = left1 * right1;
    BIgFloat ans_mul(mul);
    ans_mul.index = left.index + right.index;
    //ans_mul.sign = left.sign * right.sign;
    ans_mul.delete_leadings_zeroes();
    return ans_mul;
}

const BIgFloat operator /(const BIgFloat& left, const BIgFloat& right) {
    std::string sl = get_str(left);
    std::string sr = get_str(right);
    for (int i = 0; i < left.precision; ++i) {
        sl += '0';
    }
    BIgInt div1(sl);
    BIgInt div2(sr);
    BIgInt ans_div = div1 / div2;
    BIgFloat ans(ans_div);
    ans.index = left.precision;
    ans.delete_leadings_zeroes();
    return ans;
}
