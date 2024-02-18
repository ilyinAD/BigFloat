add_library(bignum BigFloat.cpp BigInt.cpp)
target_include_directories(bignum INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})