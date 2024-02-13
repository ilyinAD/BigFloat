//
// Created by artem on 09.02.2024.
//

#ifndef BIGFLOAT_BIGINT_H
#define BIGFLOAT_BIGINT_H
#pragma once
#include <iostream>
#include <vector>
//#include "BIgFloat.h"

namespace mathclass {
    class BIgInt {
        public:
            BIgInt() = default;
            BIgInt(const BIgInt&);
            //BIgInt(const BIgFloat&);
            ~BIgInt() = default;
            BIgInt(std::string s) {
                setBIgInt(s);
            };
            void setBIgInt(std::string);
            void delete_leadings_zeroes();
            friend bool operator <(const BIgInt& left, const BIgInt& right);
            friend bool operator >(const BIgInt& left, const BIgInt& right);
            friend bool operator ==(const BIgInt& left, const BIgInt& right);
            friend bool operator !=(const BIgInt& left, const BIgInt& right);
            friend bool operator <=(const BIgInt& left, const BIgInt& right);
            friend bool operator >=(const BIgInt& left, const BIgInt& right);
            friend const BIgInt operator +(const BIgInt& left, const BIgInt& right);
            friend const BIgInt operator -(const BIgInt& left, const BIgInt& right);
            friend const BIgInt operator *(const BIgInt& left, const BIgInt& right);
            friend const BIgInt operator +(const BIgInt& left);
            friend const BIgInt operator -(const BIgInt& left);
            //delete_leadings_zeroes()
            //void show(BIgInt&);
            std::vector<int> digit;
            int sign;
    };

}



#endif //BIGFLOAT_BIGINT_H
