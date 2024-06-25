cmake_minimum_required(VERSION 3.10)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(test_main
    test_main.cpp
    ${PROJECT_SOURCE_DIR}/src/point.cpp
    ${PROJECT_SOURCE_DIR}/src/utilities.cpp
)

add_test(NAME test_main COMMAND test_main)
