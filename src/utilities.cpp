#include "utilities.h"
#include <cmath>
#include <queue>
#include <limits>
#include <random>

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

double dijkstra(const std::vector<Point>& points) {
    int n = points.size();
    std::vector<std::vector<std::pair<double, int>>> graph(n);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double travel_time = calculate_travel_time(points[i], points[j]);
            if (j == i + 1) {
                graph[i].push_back({travel_time + 10, j});
            } else {
                int penalties = 0;
                for (int k = i + 1; k < j; ++k) {
                    penalties += points[k].penalty;
                }
                graph[i].push_back({travel_time + 10 + penalties, j});
            }
        }
    }

    std::vector<double> dist(n, std::numeric_limits<double>::infinity());
    dist[0] = 0.0;
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;
    pq.push({0.0, 0});

    while (!pq.empty()) {
        double d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : graph[u]) {
            double weight = edge.first;
            int v = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[n - 1];
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
