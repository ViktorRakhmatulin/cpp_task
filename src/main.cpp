#include <iostream>
#include <iomanip>
#include <vector>
#include "point.h"
#include "utilities.h"

int main() {
    int N;
    std::vector<Point> points;
    double result;

    while (std::cin >> N && N != 0) {
        points.clear();
        points.reserve(N + 2);
        points.emplace_back(0, 0, 0);

        for (int i = 1; i <= N; ++i) {
            double x, y;
            int penalty;
            std::cin >> x >> y >> penalty;
            points.emplace_back(x, y, penalty);
        }
        points.emplace_back(100.0, 100.0, 0);

        result = dijkstra(points);
        std::cout << std::fixed << std::setprecision(3) << "Shortest travel time (Dijkstra): " << result << std::endl;
        result = dynamic_programming(points);
        std::cout << std::fixed << std::setprecision(3) << "Shortest travel time (DP): " << result << std::endl;
    }

    return 0;
}
