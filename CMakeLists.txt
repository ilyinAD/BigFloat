cmake_minimum_required(VERSION 3.27)
project(Project)

add_subdirectory(bignum)

add_executable(Project main.cpp
        bignum/BigInt.cpp
        bignum/BigFloat.cpp
)
target_link_libraries(Project PUBLIC bignum)

target_include_directories(Project PUBLIC "${PROJECT_BINARY_DIR}")
add_subdirectory(googletest)
add_executable(tests BigNum_tests.cpp)
target_link_libraries(tests gtest gtest_main bignum)