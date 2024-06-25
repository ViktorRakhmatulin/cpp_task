cmake_minimum_required(VERSION 3.10)
project(CPP_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(main
    src/main.cpp
    src/point.cpp
    src/utilities.cpp
    src/dp_solver.cpp
    src/dijkstra_solver.cpp
)

add_subdirectory(tests)