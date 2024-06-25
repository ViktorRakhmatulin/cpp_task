#include "utilities.h"
#include <cmath>
#include <queue>
#include <limits>
#include <random>
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

double calculate_travel_time(const Point& a, const Point& b, double speed) {
    return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2)) / speed;
}

double dynamic_programming(const std::vector<Point>& points) {
    int n = points.size();
    std::vector<double> dp(n, std::numeric_limits<double>::infinity());
    dp[0] = 0.0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double travel_time = calculate_travel_time(points[i], points[j]);
            double wait_time = 10.0;
            int penalties = 0;
            for (int k = i + 1; k < j; ++k) {
                penalties += points[k].penalty;
            }
            dp[j] = std::min(dp[j], dp[i] + travel_time + wait_time + penalties);
        }
    }

    return dp[n - 1];
}


std::vector<Point> generate_random_points(int n) {
    std::vector<Point> points;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 100.0);
    std::uniform_int_distribution<int> penalty_dis(1, 10);

    for (int i = 1; i <= n; ++i) {
        double x = dis(gen);
        double y = dis(gen);
        int penalty = penalty_dis(gen);
        points.emplace_back(x, y, penalty);
    }
    points.emplace_back(100.0, 100.0, 0);
    return points;
}
