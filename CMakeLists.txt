cmake_minimum_required(VERSION 3.10)
project(CPP_Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)
include_directories(include/nlohmann)


add_executable(main
    src/main.cpp
    src/utilities.cpp
    src/dp_solver.cpp
    src/dijkstra_solver.cpp
)

add_subdirectory(tests)