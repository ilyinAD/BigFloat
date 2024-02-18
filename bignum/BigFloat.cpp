//
// Created by artem on 12.02.2024.
//

#include "BigFloat.h"
#include "BigInt.h"
#include <algorithm>
#define all(x) x.begin(), x.end()

BigFloat::BigFloat(const BigInt &num) {
    for (int i = 0; i < num.digit.size(); ++i) {
        digit.push_back(num.digit[i]);
    }
    sign = num.sign;
    index = 0;
}

BigFloat::BigFloat(std::string s) {
    if (s.size() == 1 && s[0] == '0') {
        BigFloat::digit = "0";
        BigFloat::sign = 1;
        BigFloat::index = 0;
        return;
    }
    BigFloat::index = 0;
    BigFloat::sign = 1;
    if (s.size() == 0) {
        return;
    }
    int ind = 0;
    if (s[0] == '-') {
        BigFloat::sign = -1;
        ++ind;
    }
    while (s[ind] == '0' && ind < s.size()) {
        ++ind;
    }
    if (ind == s.size()) {
        BigFloat::sign = 1;
        return;
    }

    for (long long i = s.size() - 1; i >= ind; --i) {
        if (s[i] == '.') {
            BigFloat::index = s.size() - 1 - i;
            continue;
        }
        BigFloat::digit.push_back(s[i]);
    }
    if (BigFloat::index == BigFloat::digit.size()) {
        BigFloat::digit.push_back('0');
    }
}

void BigFloat::delete_leadings_zeroes() {
    if (BigFloat::digit.size() == 1 && BigFloat::digit[0] == '0') {
        return;
    }
    std::string v = BigFloat::digit;
    int cnt = 0;
    while (BigFloat::index > 0 && BigFloat::digit[cnt] == '0') {
        --BigFloat::index;
        ++cnt;
    }
    BigFloat::digit.clear();
    for (int i = cnt; i < v.size(); ++i) {
        BigFloat::digit.push_back(v[i]);
    }
}

bool operator ==(const BigFloat& left, const BigFloat& right) {
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

bool operator <(const BigFloat& left, const BigFloat& right) {
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
    while (i != -1 || j != -1) {
        int val1 = 0;
        if (i != -1) {
            val1 = left.digit[i] - '0';
            --i;
        }
        int val2 = 0;
        if (j != -1) {
            val2 = right.digit[j] - '0';
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

bool operator <=(const BigFloat& left, const BigFloat& right) {
    return (left < right || left == right);
}

bool operator >=(const BigFloat& left, const BigFloat& right) {
    return !(left < right);
}

bool operator >(const BigFloat& left, const BigFloat& right) {
    return !(left <= right);
}

bool operator !=(const BigFloat& left, const BigFloat& right) {
    return !(left == right);
}

const BigFloat operator -(const BigFloat& left) {
    BigFloat num(left);
    num.sign *= -1;
    return num;
}

const BigFloat operator +(BigFloat& left) {
    BigFloat num(left);
    return num;
}

std::string get_str(const BigFloat& num) {
    std::string sl;
    if (num.sign == -1) {
        sl += '-';
    }
    for (int i = num.digit.size() - 1; i >= 0; --i) {
        sl += (num.digit[i]);
    }
    return sl;
}

const BigFloat operator +(const BigFloat& left, const BigFloat& right) {
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
    BigInt in1(sl);
    BigInt in2(sr);
    BigInt add = in1 + in2;
    BigFloat add_ans(add);
    add_ans.index = std::max(left.index, right.index);
    if (add_ans.index == add_ans.digit.size()) {
        add_ans.digit.push_back('0');
    }
    add_ans.delete_leadings_zeroes();
    return add_ans;

}

const BigFloat operator -(const BigFloat& left, const BigFloat& right) {
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
    BigInt in1(sl);
    BigInt in2(sr);
    BigInt sub = in1 - in2;
    BigFloat sub_ans(sub);
    sub_ans.index = std::max(left.index, right.index);
    if (sub_ans.index == sub_ans.digit.size()) {
        sub_ans.digit.push_back('0');
    }
    sub_ans.delete_leadings_zeroes();
    return sub_ans;
}

const BigFloat operator *(const BigFloat& left, const BigFloat& right) {
    std::string sl = get_str(left);
    std::string sr = get_str(right);
    BigInt left1(sl);
    BigInt right1(sr);
    BigInt mul = left1 * right1;
    BigFloat ans_mul(mul);
    ans_mul.index = left.index + right.index;
    ans_mul.delete_leadings_zeroes();
    while (ans_mul.index >= ans_mul.digit.size()) {
        ans_mul.digit.push_back('0');
    }
    return ans_mul;
}

const BigFloat operator /(const BigFloat& left, const BigFloat& right) {
    std::string sl = get_str(left);
    std::string sr = get_str(right);
    for (int i = 0; i < left.precision; ++i) {
        sl += '0';
    }
    BigInt div1(sl);
    BigInt div2(sr);
    BigInt ans_div = div1 / div2;
    BigFloat ans(ans_div);
    ans.index = left.precision + left.index - right.index;
    while (ans.index >= ans.digit.size()) {
        ans.digit.push_back('0');
    }
    ans.delete_leadings_zeroes();
    return ans;
}
