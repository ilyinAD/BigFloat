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

class BIgFloat{
public:
    BIgFloat() = default;
    BIgFloat(const BIgFloat& num);
    BIgFloat(const mathclass::BIgInt& num);
    ~BIgFloat() = default;
    BIgFloat(std::string s) {
        setBIgFloat(s);
    };
    void setBIgFloat(std::string);
    void delete_leadings_zeroes();
    friend bool operator <(const BIgFloat& left, const BIgFloat& right);
    friend bool operator >(const BIgFloat& left, const BIgFloat& right);
    friend bool operator ==(const BIgFloat& left, const BIgFloat& right);
    friend bool operator !=(const BIgFloat& left, const BIgFloat& right);
    friend bool operator <=(const BIgFloat& left, const BIgFloat& right);
    friend bool operator >=(const BIgFloat& left, const BIgFloat& right);
    friend const BIgFloat operator +(const BIgFloat& left, const BIgFloat& right);
    friend const BIgFloat operator -(const BIgFloat& left, const BIgFloat& right);
    friend const BIgFloat operator *(const BIgFloat& left, const BIgFloat& right);
    friend const BIgFloat operator /(const BIgFloat& left, const BIgFloat& right);
    friend const BIgFloat operator +(const BIgFloat& left);
    friend const BIgFloat operator -(const BIgFloat& left);
    //namespace std::chrono_literals{};
    //friend BIgFloat operator ""_bigfloat(const char *);
    //delete_leadings_zeroes()
    //void show(BIgFloat&);
    std::vector<int> digit;
    int sign;
    int index;
    const int precision = 9;
};


#endif //BIGFLOAT_BIGFLOAT_H
