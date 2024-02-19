//
// Created by artem on 19.02.2024.
//
#include "gtest/gtest.h"
#include "BigFloat.h"
#include "BigInt.h"

// String constructor tests
TEST(BigintTest, StringConstructor1) {
    BigInt obj("-0");
    ASSERT_EQ("0", obj.get_val());
    ASSERT_TRUE(obj.sign == 1);
}

TEST(BigintTest, StringConstructor2) {
    BigInt obj("-123");
    ASSERT_EQ("123", obj.get_val());
    ASSERT_TRUE(obj.sign == -1);
}

//equality operatot tests
TEST(BigintTest, EqualityTest1) {
    BigInt obj1("-123");
    BigInt obj2("123");
    ASSERT_FALSE(obj1 == obj2);
}

TEST(BigintTest, EqualityTest2) {
    BigInt obj1("234");
    BigInt obj2("235");
    ASSERT_FALSE(obj1 == obj2);
}

TEST(BigintTest, EqualityTest3) {
    BigInt obj1("123");
    BigInt obj2("123");
    ASSERT_TRUE(obj1 == obj2);
}



//lesser operator tests
TEST(BigintTest, LesserTest1) {
    BigInt obj1("-123");
    BigInt obj2("123");
    ASSERT_TRUE(obj1 < obj2);
}

TEST(BigintTest, LesserTest2) {
    BigInt obj1("234");
    BigInt obj2("235");
    ASSERT_TRUE(obj1 < obj2);
}

TEST(BigintTest, LesserTest3) {
    BigInt obj1("123");
    BigInt obj2("123");
    ASSERT_FALSE(obj1 < obj2);
}

TEST(BigintTest, LesserTest4) {
    BigInt obj1("5");
    BigInt obj2("2");
    ASSERT_FALSE(obj1 < obj2);
}

//minus operator tests
TEST(BigintTest, MinusTest1) {
    BigInt obj1("124");
    BigInt obj2("123");
    ASSERT_EQ((obj1 - obj2).get_val(), "1");
    ASSERT_TRUE((obj1 - obj2).sign == 1);
}

TEST(BigintTest, MinusTest2) {
    BigInt obj1("12");
    BigInt obj2("-100");
    ASSERT_EQ((obj1 - obj2).get_val(), "112");
    ASSERT_TRUE((obj1 - obj2).sign == 1);
}

TEST(BigintTest, MinusTest3) {
    BigInt obj1("-18");
    BigInt obj2("1");
    ASSERT_EQ((obj1 - obj2).get_val(), "19");
    ASSERT_TRUE((obj1 - obj2).sign == -1);
}

TEST(BigintTest, MinusTest4) {
    BigInt obj1("-18");
    BigInt obj2("-19");
    ASSERT_EQ((obj1 - obj2).get_val(), "1");
    ASSERT_TRUE((obj1 - obj2).sign == 1);
}

//plus operator tests
TEST(BigintTest, PlusTest1) {
    BigInt obj1("19");
    BigInt obj2("12");
    ASSERT_EQ((obj1 + obj2).get_val(), "31");
    ASSERT_TRUE((obj1 + obj2).sign == 1);
}

TEST(BigintTest, PlusTest2) {
    BigInt obj1("12");
    BigInt obj2("-100");
    ASSERT_EQ((obj1 + obj2).get_val(), "88");
    ASSERT_TRUE((obj1 + obj2).sign == -1);
}

TEST(BigintTest, PlusTest3) {
    BigInt obj1("-18");
    BigInt obj2("1");
    ASSERT_EQ((obj1 + obj2).get_val(), "17");
    ASSERT_TRUE((obj1 + obj2).sign == -1);
}

TEST(BigintTest, PlusTest4) {
    BigInt obj1("-18");
    BigInt obj2("-19");
    ASSERT_EQ((obj1 + obj2).get_val(), "37");
    ASSERT_TRUE((obj1 + obj2).sign == -1);
}

//multiply operator tests
TEST(BigintTest, MultiplyTest1) {
    BigInt obj1("8");
    BigInt obj2("0");
    ASSERT_EQ((obj1 * obj2).get_val(), "0");
    ASSERT_TRUE((obj1 * obj2).sign == 1);
}

TEST(BigintTest, MultiplyTest2) {
    BigInt obj1("11");
    BigInt obj2("-9");
    ASSERT_EQ((obj1 * obj2).get_val(), "99");
    ASSERT_TRUE((obj1 * obj2).sign == -1);
}

TEST(BigintTest, MultiplyTest3) {
    BigInt obj1("-2");
    BigInt obj2("-9");
    ASSERT_EQ((obj1 * obj2).get_val(), "18");
    ASSERT_TRUE((obj1 * obj2).sign == 1);
}

TEST(BigintTest, MultiplyTest4) {
    BigInt obj1("15");
    BigInt obj2("1");
    ASSERT_EQ((obj1 * obj2).get_val(), "15");
    ASSERT_TRUE((obj1 * obj2).sign == 1);
}

//division operator tests
TEST(BigintTest, DivisionTest1) {
    BigInt obj1("0");
    BigInt obj2("8");
    ASSERT_EQ((obj1 / obj2).get_val(), "0");
    ASSERT_TRUE((obj1 / obj2).sign == 1);
}

TEST(BigintTest, DivisionTest2) {
    BigInt obj1("5");
    BigInt obj2("-2");
    ASSERT_EQ((obj1 / obj2).get_val(), "2");
    ASSERT_TRUE((obj1 / obj2).sign == -1);
}

TEST(BigintTest, DivisionTest3) {
    BigInt obj1("15");
    BigInt obj2("-16");
    ASSERT_EQ((obj1 / obj2).get_val(), "0");
    ASSERT_TRUE((obj1 / obj2).sign == 1);
}

TEST(BigintTest, DivisionTest4) {
    BigInt obj1("-17");
    BigInt obj2("-3");
    ASSERT_EQ((obj1 / obj2).get_val(), "5");
    ASSERT_TRUE((obj1 / obj2).sign == 1);
}