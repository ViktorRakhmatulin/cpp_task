cmake_minimum_required(VERSION 3.10)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(TEST_PROJECT ${PROJECT_NAME}_test)

add_executable(${TEST_PROJECT}
    test_main.cpp
    ${PROJECT_SOURCE_DIR}/src/utilities.cpp
    ${PROJECT_SOURCE_DIR}/src/dp_solver.cpp
    ${PROJECT_SOURCE_DIR}/src/dijkstra_solver.cpp
)

target_link_libraries(${TEST_PROJECT}
    PRIVATE
        gtest
        pthread
)

include(GoogleTest)

gtest_discover_tests(${TEST_PROJECT})
