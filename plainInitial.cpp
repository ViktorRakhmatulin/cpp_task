#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, penalty;
};

double calculateTravelTime(const Point &a, const Point &b) {
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2)) / 2.0;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<Point> points(N);
        for (int i = 0; i < N; ++i) {
            cin >> points[i].x >> points[i].y >> points[i].penalty;
        }

        vector<double> dp(N + 1, 1e9); 
        dp[0] = 0.0; 
        Point prev = points[0]; 
        const double waitTime = 10.0;
        
        for (int i = 1; i < N; i++) {
            double option1 = dp[i-1] + points[i].penalty;
            double option2 = dp[i] + calculateTravelTime(prev, points[i]) + waitTime;
            if (option1 < option2) {
                dp[i] = option1;
            } else {
                dp[i] = option2;
                prev = points[i];
            }
        }

        double finalTravelTime = calculateTravelTime(points[N-1], {100, 100, 0});
        double result = dp[N-1] + finalTravelTime;
        cout.precision(3);
        cout << fixed << result << endl;
    }
    return 0;
}
