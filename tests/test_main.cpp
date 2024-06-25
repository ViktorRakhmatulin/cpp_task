#include <iostream>
#include "point.h"
#include "utilities.h"
#include <cassert>
#include <vector>

void test_calculate_travel_time() {
    Point a(0.0, 0.0, 0);
    Point b(3.0, 4.0, 0);
    assert(std::abs(calculate_travel_time(a, b) - 2.5) < 1e-9);
}

void test_dynamic_programming() {
    std::vector<Point> points = {
        {0.0, 0.0, 0}, 
        {1.0, 1.0, 1}, 
        {2.0, 2.0, 2}, 
        {100.0, 100.0, 0}
    };
    double result = dynamic_programming(points);
    assert(result > 0); // Add proper checks based on expected results
}

void test_dijkstra() {
    std::vector<Point> points = {
        {0.0, 0.0, 0}, 
        {1.0, 1.0, 1}, 
        {2.0, 2.0, 2}, 
        {100.0, 100.0, 0}
    };
    double result = dijkstra(points);
    assert(result > 0); // Add proper checks based on expected results
}

void test_generate_random_points() {
    std::vector<Point> points = generate_random_points(1000);
    assert(points.size() == 1001);
}

int main() {
    test_calculate_travel_time();
    test_dynamic_programming();
    test_dijkstra();
    test_generate_random_points();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
