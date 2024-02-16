//
// Created by artem on 09.02.2024.
//
#include <iostream>
#include "BigInt.h"
#include <algorithm>
#define all(x) x.begin(), x.end()

namespace mathclass {
    BigInt::BigInt(const mathclass::BigInt &num) {
        for (int i = 0; i < num.digit.size(); ++i) {
            digit.push_back(num.digit[i]);
        }
        sign = num.sign;
    }

//    BigInt::BigInt(const BigFloat &num) {
//        for (int i = 0; i < num.digit.size(); ++i) {
//            digit.push_back(num.digit[i]);
//        }
//        sign = num.sign;
//    }

//    std::string get_str(const BigInt& num) {
//        std::string sl;
//        for (int i = num.digit.size() - 1; i >= 0; --i) {
//            sl += (num.digit[i] + '0');
//        }
//        return sl;
//    }
    BigInt::BigInt(const std::string s) {
        if (s.size() == 1 && s[0] == '0') {
            BigInt::digit = "0";
            BigInt::sign = 1;
            return;
        }
        BigInt::sign = 1;
        if (s.size() == 0) {
            return;
        }
        int ind = 0;
        if (s[0] == '-') {
            BigInt::sign = -1;
            ++ind;
        }
        while (s[ind] == '0' && ind < s.size()) {
            ++ind;
        }
        if (ind == s.size()) {
            BigInt::sign = 1;
            BigInt::digit = "0";
            return;
        }
//        BigInt::digit = s;
//        std::reverse(all(BigInt::digit));
        for (int i = s.size() - 1; i >= ind; --i) {
            BigInt::digit += s[i];
        }
    }
    void BigInt::delete_leadings_zeroes() {
        if (BigInt::digit.size() == 1 && BigInt::digit[0] == '0') {
            return;
        }
        while (!BigInt::digit.empty() && BigInt::digit[BigInt::digit.size() - 1] == '0') {
            BigInt::digit.pop_back();
        }
        if (BigInt::digit.size() == 0) {
            BigInt::sign = 1;
            BigInt::digit.push_back('0');
            return;
        }
    }
//    void BigInt::setBIgInt(std::string s) {
//        if (s.size() == 1 && s[0] == '0') {
//            BigInt::digit = {0};
//            BigInt::sign = 1;
//            return;
//        }
//        BigInt::sign = 1;
//        if (s.size() == 0) {
//            return;
//        }
//        int ind = 0;
//        if (s[0] == '-') {
//            BigInt::sign = -1;
//            ++ind;
//        }
//        while (s[ind] == '0' && ind < s.size()) {
//            ++ind;
//        }
//        if (ind == s.size()) {
//            BigInt::sign = 1;
//            return;
//        }
//        for (long long i = s.size() - 1; i >= ind; --i) {
//            BigInt::digit.push_back(s[i] - '0');
//        }
//    }

    bool operator ==(const BigInt& left, const BigInt& right) {
        if (left.sign != right.sign || left.digit.size() != right.digit.size()) {
            return false;
        }
        for (int i = 0; i < left.digit.size(); ++i) {
            if (left.digit[i] != right.digit[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator <(const BigInt& left, const BigInt& right) {
        if (left == right) {
            return false;
        }
        if (left.sign != right.sign) {
            return left.sign < right.sign;
        }
        if (left.digit.size() != right.digit.size()) {
            return left.digit.size() < right.digit.size();
        }
        //когда будет точка то проверять колво знаков до точки и после нее при равнестве втупую
        for (int i = left.digit.size() - 1; i >= 0; --i) {
            if (left.digit[i] < right.digit[i]) {
                return true;
            } else if (left.digit[i] > right.digit[i]) {
                return false;
            }
        }
        std::cout << "WRONG" << std::endl;
    }


    bool operator <=(const BigInt& left, const BigInt& right) {
        return (left < right || left == right);
    }

    bool operator >=(const BigInt& left, const BigInt& right) {
        return !(left < right);
    }

    bool operator >(const BigInt& left, const BigInt& right) {
        return !(left <= right);
    }

    bool operator !=(const BigInt& left, const BigInt& right) {
        return !(left == right);
    }

    const BigInt operator -(const BigInt& left) {
        BigInt num(left);
        num.sign *= -1;
        return num;
    }

    const BigInt operator +(BigInt& left) {
        BigInt num(left);
        return num;
    }


    //TODO: крч надо везде где digit на строчку переписать
    const BigInt operator +(const BigInt& left, const BigInt& right) {
        int sz = right.digit.size();
        BigInt sum;
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
        sum.sign = 1;
        int shift = 0;
        for (int i = 0; i < sz; ++i) {
            int val = (left.digit[i] - '0' + right.digit[i] - '0') + shift;
            shift = val / 10;
            sum.digit.push_back((val % 10) + '0');
        }
        for (int i = sz; i < left.digit.size(); ++i) {
            int val = (left.digit[i] - '0') + shift;
            shift = val / 10;
            sum.digit.push_back((val % 10) + '0');
        }
        if (shift != 0) {
            sum.digit.push_back((shift) + '0');
        }
        sum.delete_leadings_zeroes();
        return sum;
    }

    const BigInt operator -(const BigInt& left, const BigInt& right) {
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
        int borrow = 0;
        BigInt sub;
        sub.sign = 1;
        for (int i = 0; i < right.digit.size(); ++i) {
            if (-borrow + (left.digit[i] - '0') >= (right.digit[i] - '0')) {
                sub.digit.push_back((-borrow + (left.digit[i] - '0') - (right.digit[i] - '0')) + '0');
                borrow = 0;
            } else {
                int add = 10;
//                if (left.digit[i + 1] == 0) {
//                    add = 9;
//                    sub.digit.push_back(-borrow + left.digit[i] - right.digit[i] + add);
//                }
                sub.digit.push_back((-borrow + (left.digit[i] - '0') - (right.digit[i] - '0') + add) + '0');
                borrow = 1;
            }
        }
        for (int i = right.digit.size(); i < left.digit.size(); ++i) {
            if (borrow == 0) {
                sub.digit.push_back(left.digit[i]);
                continue;
            }
            if (left.digit[i] == '0') {
                sub.digit.push_back('9');
            } else {
                sub.digit.push_back(((left.digit[i] - '0') - 1) + '0');
                borrow = 0;
            }
        }
        sub.delete_leadings_zeroes();
        return sub;
    }

    void karatsuba(int *a, int *b, int *c, int n) {
        if (n <= 100) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    c[i + j] += a[i] * b[j];
                }
            }
            return;
        }
        int k = n / 2;
        int l[k], r[k], t[n], p1[n], p2[n];
        std::fill(l, l + k, 0);
        std::fill(r, r + k, 0);
        std::fill(t, t + n, 0);
        std::fill(p1, p1 + n, 0);
        std::fill(p2, p2 + n, 0);
        for (int i = 0; i < k; i++) {
            l[i] = a[i] + a[k + i];
            r[i] = b[i] + b[k + i];
        }
        karatsuba(l, r, t, k);
        karatsuba(a, b, p1, k);
        karatsuba(a + k, b + k, p2, k);
        for (int i = 0; i < n; i++) {
            c[i] += p1[i];
            c[i + n] += p2[i];
            c[i + k] += t[i] - p1[i] - p2[i];
        }
    }

    const BigInt operator *(const BigInt& left, const int& right){
        return left * BigInt(std::to_string(right));
    }

    const BigInt operator *(const int& left, const BigInt& right){
        return BigInt(std::to_string(left)) * right;
    }

    const BigInt operator *(const BigInt& left, const BigInt& right) {
        int sz = std::max(left.digit.size(), right.digit.size());
        int l = 0;
        int r = 32;
        while (l + 1 != r) {
            int m = (l + r) / 2;
            if ((1 << m) < sz) {
                l = m;
            } else {
                r = m;
            }
        }
        int need_sz = (1 << r);
        if (sz == 1) {
            need_sz = 1;
        }
        int a[need_sz], b[need_sz];
        std::fill(a, a + need_sz, 0);
        std::fill(b, b + need_sz, 0);
        for (int i = 0; i < need_sz; ++i) {
            if (i >= left.digit.size()) {
                a[i] = 0;
            } else {
                a[i] = (left.digit[i] - '0');
            }
            if (i >= right.digit.size()) {
                b[i] = 0;
            } else {
                b[i] = (right.digit[i] - '0');
            }
        }
        int c[2 * need_sz];
        std::fill(c, c + 2 * need_sz, 0);
        karatsuba(a, b, c, need_sz);
        BigInt mul;
        mul.sign = left.sign * right.sign;
        for (int i = 0; i < 2 * need_sz; ++i) {
            int val = c[i] % 10;
            mul.digit.push_back((val) + '0');
            if ((c[i] / 10) != 0) {
                c[i + 1] += (c[i] / 10);
            }
        }
        mul.delete_leadings_zeroes();
        return mul;
    }

    int get_digital(const BigInt &left, const BigInt &right) {
//        for (int i = 9; i >= 0; --i) {
//            BigInt q = i * right;
//            if ((i * right) <= left) {
//                return i;
//            }
//        }
        int l = 0;
        int r = 10;
        while (l + 1 != r) {
            int m = (l + r) / 2;
            //BigInt q = m * right;
            if ((m * right) <= left) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }

    const BigInt operator /(const BigInt& left, const BigInt& right) {
        std::string str = right.digit;
        if (str.size() == 0 || (str[0] == '0' && str.size() == 1)) {
            std::cout << "WRONG" << std::endl;
            return BigInt("0");
        }
        BigInt right1(right);
        BigInt left1(left);
        right1.sign = 1;
        left1.sign = 1;
        if (left1 < right1) {
            return BigInt("0");
        }


        int idx = right1.digit.size();
        std::string sl;
        for (int i = left.digit.size() - 1; i > left.digit.size() - 1 - idx; --i) {
            sl += (left.digit[i]);
        }
        std::string ans;
        if (left.sign != right.sign) {
            ans += "-";
        }
        int num = get_digital(BigInt(sl), right1);
        ans += (num + '0');
        for (int i = left.digit.size() - 1 - idx; i >= 0; --i) {
            sl = (BigInt(sl) - (right1 * num)).digit;
            reverse(all(sl));
            sl += (left.digit[i]);
            num = get_digital(BigInt(sl), right1);
            ans += (num + '0');
        }
        BigInt answer(ans);
        answer.delete_leadings_zeroes();
        return answer;
    }
}


