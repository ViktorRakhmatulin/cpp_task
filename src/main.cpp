#include <iostream>
#include <iomanip>
#include <vector>
#include "point.h"
#include "utilities.h"
#include <limits>


int main() {
    int N;
    double result;

    while (true) {
        std::cout << "Enter N (0 to exit): ";
        if (!(std::cin >> N)) {
            std::cerr << "Error: Invalid input for N. Please enter a numeric value.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            continue; 
        }

        if (N == 0) {
            break; 
        }

        std::vector<Point> points = read_points(N);
        if (points.size() != N + 2) {
            continue; 
        }

        result = dynamic_programming(points);
        std::cout << std::fixed << std::setprecision(3) << "Shortest travel time (DP): " << result << std::endl;
    }

    return 0;
}
