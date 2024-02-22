//
// Created by artem on 19.02.2024.
//
#include "gtest/gtest.h"
#include "BigFloat.h"
#include "BigInt.h"

// String constructor tests
TEST(BigIntTest, StringConstructorTest1) {
    BigInt obj("-0");
    ASSERT_EQ("0", obj.get_val());
    ASSERT_TRUE(obj.sign == 1);
}

TEST(BigIntTest, StringConstructorTest2) {
    BigInt obj("-123");
    ASSERT_EQ("123", obj.get_val());
    ASSERT_TRUE(obj.sign == -1);
}

//equality operatot tests
TEST(BigIntTest, EqualityTest1) {
    BigInt obj1("-123");
    BigInt obj2("123");
    ASSERT_FALSE(obj1 == obj2);
}

TEST(BigIntTest, EqualityTest2) {
    BigInt obj1("234");
    BigInt obj2("235");
    ASSERT_FALSE(obj1 == obj2);
}

TEST(BigIntTest, EqualityTest3) {
    BigInt obj1("123");
    BigInt obj2("123");
    ASSERT_TRUE(obj1 == obj2);
}



//lesser operator tests
TEST(BigIntTest, LesserTest1) {
    BigInt obj1("-123");
    BigInt obj2("123");
    ASSERT_TRUE(obj1 < obj2);
}

TEST(BigIntTest, LesserTest2) {
    BigInt obj1("234");
    BigInt obj2("235");
    ASSERT_TRUE(obj1 < obj2);
}

TEST(BigIntTest, LesserTest3) {
    BigInt obj1("123");
    BigInt obj2("123");
    ASSERT_FALSE(obj1 < obj2);
}

TEST(BigIntTest, LesserTest4) {
    BigInt obj1("5");
    BigInt obj2("2");
    ASSERT_FALSE(obj1 < obj2);
}

//minus operator tests
TEST(BigIntTest, MinusTest1) {
    BigInt obj1("124");
    BigInt obj2("123");
    ASSERT_EQ((obj1 - obj2).get_val(), "1");
    ASSERT_TRUE((obj1 - obj2).sign == 1);
    show(obj1);
    std::cerr << " - ";
    show(obj2);
    std::cerr << " = ";
    show(obj1 - obj2);
    std::cerr << '\n';
}

TEST(BigIntTest, MinusTest2) {
    BigInt obj1("12");
    BigInt obj2("-100");
    ASSERT_EQ((obj1 - obj2).get_val(), "112");
    ASSERT_TRUE((obj1 - obj2).sign == 1);
}

TEST(BigIntTest, MinusTest3) {
    BigInt obj1("-18");
    BigInt obj2("1");
    ASSERT_EQ((obj1 - obj2).get_val(), "19");
    ASSERT_TRUE((obj1 - obj2).sign == -1);
}

TEST(BigIntTest, MinusTest4) {
    BigInt obj1("-123");
    BigInt obj2("-9012");
    ASSERT_EQ((obj1 - obj2).get_val(), "8889");
    ASSERT_TRUE((obj1 - obj2).sign == 1);
}

//plus operator tests
TEST(BigIntTest, PlusTest1) {
    BigInt obj1("19");
    BigInt obj2("12");
    ASSERT_EQ((obj1 + obj2).get_val(), "31");
    ASSERT_TRUE((obj1 + obj2).sign == 1);
    show(obj1);
    std::cerr << " + ";
    show(obj2);
    std::cerr << " = ";
    show(obj1 + obj2);
    std::cerr << '\n';
}

TEST(BigIntTest, PlusTest2) {
    BigInt obj1("12");
    BigInt obj2("-100");
    ASSERT_EQ((obj1 + obj2).get_val(), "88");
    ASSERT_TRUE((obj1 + obj2).sign == -1);
}

TEST(BigIntTest, PlusTest3) {
    BigInt obj1("-18");
    BigInt obj2("1");
    ASSERT_EQ((obj1 + obj2).get_val(), "17");
    ASSERT_TRUE((obj1 + obj2).sign == -1);
}

TEST(BigIntTest, PlusTest4) {
    BigInt obj1("9999");
    BigInt obj2("1");
    ASSERT_EQ((obj1 + obj2).get_val(), "10000");
    ASSERT_TRUE((obj1 + obj2).sign == 1);
}

//multiply operator tests
TEST(BigIntTest, MultiplyTest1) {
    BigInt obj1("8");
    BigInt obj2("0");
    ASSERT_EQ((obj1 * obj2).get_val(), "0");
    ASSERT_TRUE((obj1 * obj2).sign == 1);
    show(obj1);
    std::cerr << " * ";
    show(obj2);
    std::cerr << " = ";
    show(obj1 * obj2);
    std::cerr << '\n';
}

TEST(BigIntTest, MultiplyTest2) {
    BigInt obj1("11");
    BigInt obj2("-9");
    ASSERT_EQ((obj1 * obj2).get_val(), "99");
    ASSERT_TRUE((obj1 * obj2).sign == -1);
}

TEST(BigIntTest, MultiplyTest3) {
    BigInt obj1("-2");
    BigInt obj2("-9");
    ASSERT_EQ((obj1 * obj2).get_val(), "18");
    ASSERT_TRUE((obj1 * obj2).sign == 1);
}

TEST(BigIntTest, MultiplyTest4) {
    BigInt obj1("1092");
    BigInt obj2("1809");
    ASSERT_EQ((obj1 * obj2).get_val(), "1975428");
    ASSERT_TRUE((obj1 * obj2).sign == 1);
}

//division operator tests
TEST(BigIntTest, DivisionTest1) {
    BigInt obj1("0");
    BigInt obj2("8");
    ASSERT_EQ((obj1 / obj2).get_val(), "0");
    ASSERT_TRUE((obj1 / obj2).sign == 1);
    show(obj1);
    std::cerr << " / ";
    show(obj2);
    std::cerr << " = ";
    show(obj1 / obj2);
    std::cerr << '\n';
}

TEST(BigIntTest, DivisionTest2) {
    BigInt obj1("5");
    BigInt obj2("-2");
    ASSERT_EQ((obj1 / obj2).get_val(), "2");
    ASSERT_TRUE((obj1 / obj2).sign == -1);
}

TEST(BigIntTest, DivisionTest3) {
    BigInt obj1("15");
    BigInt obj2("-16");
    ASSERT_EQ((obj1 / obj2).get_val(), "0");
    ASSERT_TRUE((obj1 / obj2).sign == 1);
}

TEST(BigIntTest, DivisionTest4) {
    BigInt obj1("-1789");
    BigInt obj2("-35");
    ASSERT_EQ((obj1 / obj2).get_val(), "51");
    ASSERT_TRUE((obj1 / obj2).sign == 1);
}

// String constructor tests
TEST(BigFloatTest, StringConstructorTest1) {
    BigFloat obj("-0");
    ASSERT_EQ("0", obj.get_val());
    ASSERT_TRUE(obj.sign == 1);
}

TEST(BigFloatTest, StringConstructorTest2) {
    BigFloat obj("-123.908");
    ASSERT_EQ("123908", obj.get_val());
    ASSERT_TRUE(obj.sign == -1);
    ASSERT_TRUE(obj.index == 3);
}

// Equality operator tests
TEST(BigFloatTest, EqualityTest1) {
    BigFloat obj1("12");
    BigFloat obj2("12");
    ASSERT_TRUE(obj1 == obj2);
}

TEST(BigFloatTest, EqualityTest2) {
    BigFloat obj1("1.2");
    BigFloat obj2("12");
    ASSERT_FALSE(obj1 == obj2);
}

TEST(BigFloatTest, EqualityTest3) {
    BigFloat obj1("012.0130");
    BigFloat obj2("12.013");
    ASSERT_TRUE(obj1 == obj2);
}

//Lesser operator tests
TEST(BigFloatTest, LesserTest1) {
    BigFloat obj1("12");
    BigFloat obj2("12");
    ASSERT_FALSE(obj1 < obj2);
}

TEST(BigFloatTest, LesserTest2) {
    BigFloat obj1("12");
    BigFloat obj2("1.3");
    ASSERT_FALSE(obj1 < obj2);
}

TEST(BigFloatTest, LesserTest3) {
    BigFloat obj1("0.99");
    BigFloat obj2("1.01");
    ASSERT_TRUE(obj1 < obj2);
}

TEST(BigFloatTest, LesserTest4) {
    BigFloat obj1("0.01");
    BigFloat obj2("-11.01");
    ASSERT_FALSE(obj1 < obj2);
}

//minus operatot tests
TEST(BigFloatTest, MinusTest1) {
    BigFloat obj1("0.99");
    BigFloat obj2("1.01");
    BigFloat obj3("-0.02");
    ASSERT_TRUE((obj1 - obj2) == obj3);
    show(obj1);
    std::cerr << " - ";
    show(obj2);
    std::cerr << " = ";
    show(obj1 - obj2);
    std::cerr << '\n';
}

TEST(BigFloatTest, MinusTest2) {
    BigFloat obj1("12.1");
    BigFloat obj2("-1.9");
    BigFloat obj3("14");
    ASSERT_TRUE((obj1 - obj2) == obj3);
}

TEST(BigFloatTest, MinusTest3) {
    BigFloat obj1("-11.0100");
    BigFloat obj2("2.9");
    BigFloat obj3("-13.91");
    ASSERT_TRUE((obj1 - obj2) == obj3);
}

//plus operatot tests
TEST(BigFloatTest, PlusTest1) {
    BigFloat obj1("0.99");
    BigFloat obj2("1.01");
    BigFloat obj3("2");
    ASSERT_TRUE((obj1 + obj2) == obj3);
    show(obj1);
    std::cerr << " + ";
    show(obj2);
    std::cerr << " = ";
    show(obj1 + obj2);
    std::cerr << '\n';
}

TEST(BigFloatTest, PlusTest2) {
    BigFloat obj1("12.1");
    BigFloat obj2("-1.9");
    BigFloat obj3("10.2");
    ASSERT_TRUE((obj1 + obj2) == obj3);
}

TEST(BigFloatTest, PlusTest3) {
    BigFloat obj1("-11.0100");
    BigFloat obj2("-2.9");
    BigFloat obj3("-13.91");
    ASSERT_TRUE((obj1 + obj2) == obj3);
}

//multiply operatot tests
TEST(BigFloatTest, MultiplyTest1) {
    BigFloat obj1("1.2");
    BigFloat obj2("1.3");
    BigFloat obj3("1.56");
    ASSERT_TRUE((obj1 * obj2) == obj3);
    show(obj1);
    std::cerr << " * ";
    show(obj2);
    std::cerr << " = ";
    show(obj1 * obj2);
    std::cerr << '\n';
}

TEST(BigFloatTest, MultiplyTest2) {
    BigFloat obj1("12.1");
    BigFloat obj2("-0");
    BigFloat obj3("0");
    ASSERT_TRUE((obj1 * obj2) == obj3);
}

TEST(BigFloatTest, MultiplyTest3) {
    BigFloat obj1("19.22");
    BigFloat obj2("12.32");
    BigFloat obj3("236.7904");
    ASSERT_TRUE((obj1 * obj2) == obj3);
}

//division operatot tests
TEST(BigFloatTest, DivisionTest1) {
    BigFloat obj1("0.0");
    BigFloat obj2("1.3");
    BigFloat obj3("0");
    ASSERT_TRUE((obj1 / obj2) == obj3);
    show(obj1);
    std::cerr << " / ";
    show(obj2);
    std::cerr << " = ";
    show(obj1 / obj2);
    std::cerr << '\n';
}

TEST(BigFloatTest, DivisionTest2) {
    BigFloat obj1("-5");
    BigFloat obj2("2");
    BigFloat obj3("-2.5");
    ASSERT_TRUE((obj1 / obj2) == obj3);
}

TEST(BigFloatTest, DivisionTest3) {
    BigFloat obj1("-2.2");
    BigFloat obj2("-11");
    BigFloat obj3("0.2");
    ASSERT_TRUE((obj1 / obj2) == obj3);
}

//Calculate Pi test

TEST(BigFloatTest, CalculatePiTest) {
    BigFloat obj2 = calculate_pi(100);
    std::string str = obj2.get_val().substr(0, 100);
    ASSERT_TRUE(str == "3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067");
}