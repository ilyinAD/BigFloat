//
// Created by artem on 19.02.2024.
//
#include "gtest/gtest.h"
#include "BigFloat.h"
#include "BigInt.h"

// Default constructor test
TEST(BigintTest, testDefaultConstructor) {
    BigInt bigint;
    ASSERT_EQ("0", bigint.digit);
    ASSERT_FALSE(bigint.sign == 1);
}
int main(){

};