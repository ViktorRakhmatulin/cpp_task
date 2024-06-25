#include <iostream>
#include <iomanip>
#include <vector>
#include "point.h"
#include "utilities.h"
#include <limits>

bool read_point(double& x, double& y, int& penalty) {
    if (!(std::cin >> x >> y >> penalty)) {
        std::cerr << "Error: Invalid input for point coordinates or penalty. Please enter numeric values.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

std::vector<Point> read_points(int N) {
    std::vector<Point> points;
    points.reserve(N + 2);
    points.emplace_back(0, 0, 0); 

    for (int i = 1; i <= N; ++i) {
        double x, y;
        int penalty;
        if (!read_point(x, y, penalty)) {
            points.clear(); 
            break; 
        }
        points.emplace_back(x, y, penalty);
    }

    points.emplace_back(100.0, 100.0, 0); 
    return points;
}

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
