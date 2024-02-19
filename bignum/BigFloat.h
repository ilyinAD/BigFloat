//
// Created by artem on 12.02.2024.
//

#ifndef BIGFLOAT_BIGFLOAT_H
#define BIGFLOAT_BIGFLOAT_H
#pragma once
#include "BigInt.h"
#include <iostream>
#include <vector>

class BigFloat{
public:
    BigFloat() = default;
    BigFloat(const BigFloat& other) {
        this->sign = other.sign;
        this->index = other.index;
        this->digit = other.digit;
    }
    BigFloat(const BigInt& num);
    ~BigFloat() = default;
    BigFloat(std::string s);
    std::string get_val();
    friend bool operator <(const BigFloat& left, const BigFloat& right);
    friend bool operator >(const BigFloat& left, const BigFloat& right);
    friend bool operator ==(const BigFloat& left, const BigFloat& right);
    friend bool operator !=(const BigFloat& left, const BigFloat& right);
    friend bool operator <=(const BigFloat& left, const BigFloat& right);
    friend bool operator >=(const BigFloat& left, const BigFloat& right);
    friend const BigFloat operator +(const BigFloat& left, const BigFloat& right);
    friend const BigFloat operator -(const BigFloat& left, const BigFloat& right);
    friend const BigFloat operator *(const BigFloat& left, const BigFloat& right);
    friend const BigFloat operator /(const BigFloat& left, const BigFloat& right);
    friend const BigFloat operator +(const BigFloat& left);
    friend const BigFloat operator -(const BigFloat& left);
    std::string digit;
    int sign;
    int index;
    int precision = 101;
    private:
        void delete_leadings_zeroes();
};


#endif //BIGFLOAT_BIGFLOAT_H
