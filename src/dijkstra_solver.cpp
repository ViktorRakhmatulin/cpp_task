#include "dijkstra_solver.h"
#include "utilities.h"
#include <vector>
#include <queue>
#include <limits>

double DijkstraSolver::solve(const std::vector<Point>& points) const {
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
