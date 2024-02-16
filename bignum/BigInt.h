//
// Created by artem on 09.02.2024.
//

#ifndef BIGFLOAT_BIGINT_H
#define BIGFLOAT_BIGINT_H
#pragma once
#include <iostream>
#include <vector>
//#include "BigFloat.h"

namespace mathclass {
    class BigInt {
        public:
            BigInt() = default;
            BigInt(const BigInt&);
            ~BigInt() = default;
            BigInt(const std::string s);
            friend bool operator <(const BigInt& left, const BigInt& right);
            friend bool operator >(const BigInt& left, const BigInt& right);
            friend bool operator ==(const BigInt& left, const BigInt& right);
            friend bool operator !=(const BigInt& left, const BigInt& right);
            friend bool operator <=(const BigInt& left, const BigInt& right);
            friend bool operator >=(const BigInt& left, const BigInt& right);
            friend const BigInt operator +(const BigInt& left, const BigInt& right);
            friend const BigInt operator -(const BigInt& left, const BigInt& right);
            friend const BigInt operator *(const BigInt& left, const BigInt& right);
            friend const BigInt operator *(const BigInt& left, const int& right);
            friend const BigInt operator *(const int& left, const BigInt& right);
            friend const BigInt operator /(const BigInt& left, const BigInt& right);
            friend const BigInt operator +(const BigInt& left);
            friend const BigInt operator -(const BigInt& left);
            //std::vector<int> digit;
            std::string digit;
            int sign;
    private:
        void delete_leadings_zeroes();
    };

}



#endif //BIGFLOAT_BIGINT_H