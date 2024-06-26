#include "dp_solver.h"
#include "utilities.h"
#include <vector>
#include <limits>
#include <cmath>

double DPSolver::solve(const std::vector<Point>& points) const {
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
