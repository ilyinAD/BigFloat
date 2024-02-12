cmake_minimum_required(VERSION 3.27)
project(BigFloat)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(BigInt)
add_subdirectory(BIgFloat)

add_executable(BigFloat main.cpp
        BigInt/BIgInt.cpp
        BIgFloat/BIgFloat.cpp
        )

target_link_libraries(BigFloat PUBLIC BigInt BIgFloat)

target_include_directories(BigFloat PUBLIC "${PROJECT_BINARY_DIR}"
                                            "${PROJECT_SOURCE_DIR}/BigInt"
                                            "${PROJECT_SOURCE_DIR}/BIgFloat")