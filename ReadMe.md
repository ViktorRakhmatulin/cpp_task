# Optimal Travel Time Calculator

## Description

This project calculates the optimal travel time between points, taking into account travel distances, wait times, and penalties associated with intermediate points. It provides two algorithms to find the shortest travel time:

- **Dynamic Programming (DP)**
- **Dijkstra's Algorithm**

## Files

**main.cpp**:
- Reads input data, calculates travel time using dynamic programming (DP) algorithm.

**point.h**:
- Defines the `Point` structure used throughout the project.

**utilities.h**:
- Declares utility functions used in the project.

**solver.h**:
- Defines an abstract class for solving problems.

**dp_solver.cpp**:
- Implements dynamic programming algorithm for solving specific problems.

**dijkstra_solver.cpp**:
- Implements Dijkstra's algorithm for solving specific problems.

**input.txt**:
- Contains sample input data for testing the program.

## Dependencies

- gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.2) 
- CMake

## Project Structure
```
cpp_project/
├── include/
│   ├── point.h
│   ├── utilities.h
│   ├── solver.h
│   ├── dp_solver.h
│   └── dijkstra_solver.h
├── src/
│   ├── main.cpp
│   ├── utilities.cpp
│   ├── dp_solver.cpp
│   └── dijkstra_solver.cpp
├── tests/
│   ├── test_main.cpp
│   └── CMakeLists.txt
├── CMakeLists.txt
└── input.txt
```
### Building

1. **Clone the repository:**


2. **Create and navigate to the build directory:**
    ```
    mkdir build
    cd build
    ```

3. **Generate build files with CMake:**
    ```
    cmake ..
    ```

4. **Compile the project:**
    ```
    make
    ```
### Running

1. **Execute the binary:**
    ```
    ./main
    ./tests/test_main
    ```

2. **Input:**
   - Enter the number of points `N` (excluding start/end points).
   - For each point, input the `x` and `y` coordinates followed by the penalty.
   - Enter `0` to exit.

3. **Output:**
   - Shortest travel time using dynamic programming.

**Further Improvements:**
- replace custom implementation of dijkstra and graph with GTSAM and g2o libs 
- txt to json to enhance readability
- CI/CD pipeline implementation
- Deb package generation
    
