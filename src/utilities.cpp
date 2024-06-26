#include "utilities.h"
#include <cmath>
#include <queue>
#include <limits>
#include <iostream>
#include <iomanip>

bool read_point(double& x, double& y, int& penalty) {
    if (!(std::cin >> x >> y >> penalty)) {
        std::cerr << "Error: Invalid input for point coordinates or penalty. Please enter numeric values.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

std::vector<Point> read_points(int n) {
    std::vector<Point> points;
    const Point start(0.0, 0.0, 0);
    const Point end(100.0, 100.0, 0);
    int totalPoints = n + 2; 
    points.reserve(totalPoints);
    points.push_back(start); 

    for (int i = 1; i <= n; ++i) {
        double x, y;
        int penalty;
        if (!read_point(x, y, penalty)) {
            points.clear(); 
            break; 
        }
        points.emplace_back(x, y, penalty);
    }

    points.push_back(end); 
    return points;
}

double calculate_travel_time(const Point& a, const Point& b, double speed) {
    return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2)) / speed;
}


