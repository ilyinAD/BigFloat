//
// Created by artem on 12.02.2024.
//

#ifndef BIGFLOAT_BIGFLOAT_H
#define BIGFLOAT_BIGFLOAT_H
#pragma once
#include "BigInt.h"
#include <iostream>
#include <vector>
//using namespace mathclass;

class BigFloat{
public:
    BigFloat() = default;
    BigFloat(const BigFloat& other) {
        this->sign = other.sign;
        this->index = other.index;
        this->digit = other.digit;
    }
    //BigFloat(const BigFloat& num);
    BigFloat(const mathclass::BigInt& num);
    ~BigFloat() = default;
    BigFloat(std::string s);
//    void setBIgFloat(std::string);
//    void delete_leadings_zeroes();
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
    //namespace std::chrono_literals{};
    //friend BigFloat operator ""_bigfloat(const char *);
    //delete_leadings_zeroes()
    //void show(BigFloat&);
    //std::vector<int> digit;
    std::string digit;
    int sign;
    int index;
    int precision = 101;
    private:
        void delete_leadings_zeroes();
};


#endif //BIGFLOAT_BIGFLOAT_H
