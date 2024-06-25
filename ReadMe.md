# Optimal Travel Time Calculator

## Description

This project calculates the optimal travel time between points, taking into account travel distances, wait times, and penalties associated with intermediate points. It provides two algorithms to find the shortest travel time:

- **Dynamic Programming (DP)**
- **Dijkstra's Algorithm**

## Files

- **main.cpp**: Entry point, reads input and calculates travel time using DP.
- **point.h**: Defines the `Point` structure.
- **point.cpp**: Implements the `Point` structure.
- **utilities.h**: Declares utility functions.
- **utilities.cpp**: Implements utility functions.
- **test_main.cpp**: Contains tests for the implemented functions.
- **CMakeLists.txt**: Configuration file for CMake.

## Dependencies

- C++ compiler supporting C++11 or later
- CMake

## Usage

### Building

1. **Clone the repository:**


2. **Create and navigate to the build directory:**
    mkdir build
    cd build

3. **Generate build files with CMake:**
    cmake ..


4. **Compile the project:**
    make

### Running

1. **Execute the binary:**
    ./main
    ./tests/test_main


2. **Input:**
   - Enter the number of points `N` (excluding start/end points).
   - For each point, input the `x` and `y` coordinates followed by the penalty.
   - Enter `0` to exit.

3. **Output:**
   - Shortest travel time using dynamic programming.
