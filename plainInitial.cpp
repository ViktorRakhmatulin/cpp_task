#include <iostream>
#include <fstream> 
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, penalty;
};

double calculateTravelTime(const Point &a, const Point &b, const double speed = 2.0) {
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2)) / speed;
}

int main() {
    ifstream infile("input.txt"); 
    if (!infile) {
        cerr << "Error: Unable to open input file.\n";
        return 1;
    }

    int N;
    while (infile >> N && N != 0) {
        vector<Point> points(N);

        for (int i = 0; i < N; ++i) {
            infile >> points[i].x >> points[i].y >> points[i].penalty;
        }

        vector<double> dp(N + 1, 1e9); 
        dp[0] = 0.0; 
        Point prev = {0,0,0}; 
        const double waitTime = 10.0;
        
        for (int i = 1; i <= N; i++) {
            double option1 = dp[i-1] + points[i-1].penalty;
            double option2 = dp[i-1] + calculateTravelTime(prev, points[i-1]) + waitTime;
            if (option1 < option2) {
                dp[i] = option1;
            } else {
                dp[i] = option2;
                prev = points[i-1];
            }
        }

        double finalTravelTime = calculateTravelTime(prev, {100, 100, 0});
        double result = dp[N] + finalTravelTime;
        cout.precision(3);
        cout << fixed << result << endl;
    }

    infile.close();  
    return 0;
}
