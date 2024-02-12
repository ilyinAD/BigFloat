//
// Created by artem on 09.02.2024.
//
#include <iostream>
#include "BIgInt.h"
namespace mathclass {
    BIgInt::BIgInt(const mathclass::BIgInt &num) {
        for (int i = 0; i < num.digit.size(); ++i) {
            digit.push_back(num.digit[i]);
        }
        sign = num.sign;
    }


    void BIgInt::delete_leadings_zeroes() {
        while (!BIgInt::digit.empty() && BIgInt::digit[BIgInt::digit.size() - 1] == 0) {
            BIgInt::digit.pop_back();
        }
        if (BIgInt::digit.size() == 0) {
            BIgInt::sign = 1;
            return;
        }
    }
    void BIgInt::setBIgInt(std::string s) {
        BIgInt::sign = 1;
        if (s.size() == 0) {
            return;
        }
        int ind = 0;
        if (s[0] == '-') {
            BIgInt::sign = -1;
            ++ind;
        }
        while (s[ind] == '0' && ind < s.size()) {
            ++ind;
        }
        if (ind == s.size()) {
            BIgInt::sign = 1;
            return;
        }
        for (long long i = s.size() - 1; i >= ind; --i) {
            BIgInt::digit.push_back(s[i] - '0');
        }
    }

    bool operator ==(const BIgInt& left, const BIgInt& right) {
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

    bool operator <(const BIgInt& left, const BIgInt& right) {
        if (left == right) {
            return false;
        }
        if (left.digit.size() != right.digit.size()) {
            return left.digit.size() < right.digit.size();
        }
        //когда будет точка то проверять колво знаков до точки и после нее при равнестве втупую
        for (int i = 0; i < left.digit.size(); ++i) {
            if (left.digit[i] < right.digit[i]) {
                return true;
            } else if (left.digit[i] > right.digit[i]) {
                return false;
            }
        }
        std::cout << "WRONG" << std::endl;
    }


    bool operator <=(const BIgInt& left, const BIgInt& right) {
        return (left < right || left == right);
    }

    bool operator >=(const BIgInt& left, const BIgInt& right) {
        return !(left < right);
    }

    bool operator >(const BIgInt& left, const BIgInt& right) {
        return !(left <= right);
    }

    bool operator !=(const BIgInt& left, const BIgInt& right) {
        return !(left == right);
    }

    const BIgInt operator -(const BIgInt& left) {
        BIgInt num(left);
        num.sign *= -1;
        return num;
    }

    const BIgInt operator +(BIgInt& left) {
        BIgInt num(left);
        return num;
    }

    const BIgInt operator +(const BIgInt& left, const BIgInt& right) {
        int sz = right.digit.size();
        BIgInt sum;
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
            int val = left.digit[i] + right.digit[i] + shift;
            shift = val / 10;
            sum.digit.push_back(val % 10);
        }
        for (int i = sz; i < left.digit.size(); ++i) {
            int val = left.digit[i] + shift;
            shift = val / 10;
            sum.digit.push_back(val % 10);
        }
        if (shift != 0) {
            sum.digit.push_back(shift);
        }
        return sum;
    }

    const BIgInt operator -(const BIgInt& left, const BIgInt& right) {
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
        BIgInt sub;
        sub.sign = 1;
        for (int i = 0; i < right.digit.size(); ++i) {
            if (-borrow + left.digit[i] >= right.digit[i]) {
                sub.digit.push_back(-borrow + left.digit[i] - right.digit[i]);
                borrow = 0;
            } else {
                int add = 10;
//                if (left.digit[i + 1] == 0) {
//                    add = 9;
//                    sub.digit.push_back(-borrow + left.digit[i] - right.digit[i] + add);
//                }
                sub.digit.push_back(-borrow + left.digit[i] - right.digit[i] + add);
                borrow = 1;
            }
        }
        for (int i = right.digit.size(); i < left.digit.size(); ++i) {
            if (borrow == 0) {
                sub.digit.push_back(left.digit[i]);
                continue;
            }
            if (left.digit[i] == 0) {
                sub.digit.push_back(9);
            } else {
                sub.digit.push_back(left.digit[i] - 1);
                borrow = 0;
            }
        }
        sub.delete_leadings_zeroes();
        return sub;
    }
}