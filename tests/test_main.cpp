#include <gtest/gtest.h>
#include <fstream>
#include <vector>
#include <chrono>
#include "point.h"
#include "utilities.h"
#include "solver.h"
#include "dp_solver.h"
#include "dijkstra_solver.h"
#include <random>

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

TEST(TravelTimeTests, CalculateTravelTime) {
    Point a(0.0, 0.0, 0);
    Point b(3.0, 4.0, 0);
    EXPECT_NEAR(calculate_travel_time(a, b), 2.5, 1e-9);
}

TEST(TravelTimeTests, DynamicProgramming) {
    DPSolver dpSolver;
    std::vector<std::vector<Point>> pointsList = read_points_from_file("input.txt");
    std::vector<float> gtResults = {90.711, 156.858, 110.711};
    int i = 0;
    for (const auto& points : pointsList) {
        double result = dpSolver.solve(points);
        EXPECT_NEAR(result, gtResults[i], 1e-3);
        i++;
    }
}

TEST(TravelTimeTests, Dijkstra) {
    DijkstraSolver dijkstraSolver;
    std::vector<std::vector<Point>> pointsList = read_points_from_file("input.txt");
    std::vector<float> gtResults = {90.711, 156.858, 110.711};
    int i = 0;
    for (const auto& points : pointsList) {
        double result = dijkstraSolver.solve(points);
        EXPECT_NEAR(result, gtResults[i], 1e-3);
        i++;
    }
}

TEST(PerformanceTests, GenerateRandomPoints) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Point> points = generate_random_points(1000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    EXPECT_EQ(points.size(), 1001);
    EXPECT_LT(duration.count(), 1.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
