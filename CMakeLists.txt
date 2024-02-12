cmake_minimum_required(VERSION 3.27)
project(Project)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(bignum)

add_executable(Project main.cpp
        bignum/BIgInt.cpp
        bignum/BIgFloat.cpp
)

target_link_libraries(Project PUBLIC bignum)

target_include_directories(Project PUBLIC "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/BigInt"
        "${PROJECT_SOURCE_DIR}/BIgFloat")