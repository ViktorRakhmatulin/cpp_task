#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <fstream>
#include <iomanip>
#include <random>

using namespace std;

struct Point {
    double x;
    double y;
    int penalty;

    Point(double x, double y, int penalty) : x(x), y(y), penalty(penalty) {}
};


double calculate_travel_time(const Point& a, const Point& b, double speed = 2.0) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)) / speed;
}

double dynamic_programming(const vector<Point>& points) {
    int n = points.size();
    vector<double> dp(n, numeric_limits<double>::infinity());
    dp[0] = 0.0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double travel_time = calculate_travel_time(points[i], points[j]);
            double wait_time = 10.0;
            int penalties = 0;
            for (int k = i + 1; k < j; ++k) {
                penalties += points[k].penalty;
            }
            dp[j] = min(dp[j], dp[i] + travel_time + wait_time + penalties);
        }
    }

    return dp[n - 1];
}

double dijkstra(const vector<Point>& points) {
    int n = points.size();
    vector<vector<pair<double, int>>> graph(n);

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

    vector<double> dist(n, numeric_limits<double>::infinity());
    dist[0] = 0.0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0.0, 0});

    while (!pq.empty()) {
        double d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
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

// stress test_case
vector<Point> generate_random_points(int n) {
    vector<Point> points;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 100.0);
    uniform_int_distribution<int> penalty_dis(1, 10);

    for (int i = 1; i <= n; ++i) {
        double x = dis(gen);
        double y = dis(gen);
        int penalty = penalty_dis(gen);
        points.emplace_back(x, y, penalty);
    }
    points.emplace_back(100.0, 100.0, 0); 
    return points;
}
int main() {

    ifstream infile("input.txt");
    if (!infile) {
        cerr << "Error: Unable to open input file.\n";
        return 1;
    }

    int N;
    vector<Point> points;
    double result;

    // Process test cases from input.txt
    while (infile >> N && N != 0) {
        points.clear();
        points.reserve(N + 2);
        points.emplace_back(0, 0, 0);

        for (int i = 1; i <= N; ++i) {
            double x, y;
            int penalty;
            infile >> x >> y >> penalty;
            points.emplace_back(x, y, penalty);
        }
        points.emplace_back(100.0, 100.0, 0);

        result = dijkstra(points);
        
        cout << fixed << setprecision(3) << "Shortest travel time: " << result << endl;
        result = dynamic_programming(points);
        cout << fixed << setprecision(3) << "Shortest travel time: " << result << endl;
        
    }

    // Generate random points for N = 1000
    N = 1000;
    points = generate_random_points(N);
    result = dijkstra(points);
    cout << fixed << setprecision(3) << "Shortest travel time: " << result << endl;

    return 0;
}