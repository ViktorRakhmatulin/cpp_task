#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <chrono>
#include "point.h"
#include "utilities.h"

std::vector<std::vector<Point>> read_points_from_file(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) {
        throw std::runtime_error("Error: Unable to open input file.");
    }

    std::vector<std::vector<Point>> pointsList;
    int N;

    while (infile >> N && N != 0) {
        std::vector<Point> points;
        points.reserve(N + 2);
        points.emplace_back(0.0, 0.0, 0);

        for (int i = 1; i <= N; ++i) {
            double x, y;
            int penalty;
            infile >> x >> y >> penalty;
            points.emplace_back(x, y, penalty);
        }

        points.emplace_back(100.0, 100.0, 0.0);
        pointsList.push_back(std::move(points)); 
    }

    return pointsList;
}

void test_calculate_travel_time() {
    Point a(0.0, 0.0, 0);
    Point b(3.0, 4.0, 0);
    assert(std::abs(calculate_travel_time(a, b) - 2.5) < 1e-9);
}

void test_dynamic_programming() {
    try {
        std::vector<std::vector<Point>> pointsList = read_points_from_file("input.txt");
        std::vector<float> gtResults = {90.711, 156.858,110.711};
        int i = 0;
        for (const auto& points : pointsList) {
            double result = dynamic_programming(points);
            assert(std::abs(result - gtResults[i]) < 1e-3);
            // std::cout << std::fixed << std::setprecision(3) << "Shortest travel time (DP): " << result << std::endl;
            i++;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        throw; 
    }
}

void test_dijkstra() {
    try {
        std::vector<std::vector<Point>> pointsList = read_points_from_file("input.txt");
        std::vector<float> gtResults = {90.711, 156.858,110.711};
        int i = 0;
        for (const auto& points : pointsList) {
            double result = dijkstra(points);
            assert(std::abs(result - gtResults[i]) < 1e-3);
            i++;
            // std::cout << std::fixed << std::setprecision(3) << "Shortest travel time (Dijkstra): " << result << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        throw; 
    }
    }

void test_generate_random_points() {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Point> points = generate_random_points(1000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    assert(points.size() == 1001);
    assert(duration.count() < 1.0); 
}

int main() {
    try {
        test_calculate_travel_time();
        test_dynamic_programming();
        test_dijkstra();
        test_generate_random_points();
        std::cout << "All tests passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
