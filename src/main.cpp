#include <iostream>
#include <iomanip>
#include <vector>
#include "point.h"
#include "utilities.h"
#include "solver.h"
#include "dp_solver.h"
#include "dijkstra_solver.h"
#include <limits>

int main() {
    int n;
    double result;

    DPSolver dpSolver;
    DijkstraSolver dijkstraSolver;

    while (true) {
        std::cout << "Enter N (0 to exit): ";
        if (!(std::cin >> n)) {
            std::cerr << "Error: Invalid input for N. Please enter a numeric value.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            continue; 
        }

        if (n == 0) {
            break; 
        }
        int totalPoints = n + 2;
        std::vector<Point> points = read_points(n);
        if (points.size() != totalPoints) {
            continue; 
        }

        result = dpSolver.solve(points);
        std::cout << std::fixed << std::setprecision(3) << "Shortest travel time (DP): " << result << std::endl;

        result = dijkstraSolver.solve(points);
        std::cout << std::fixed << std::setprecision(3) << "Shortest travel time (Dijkstra): " << result << std::endl;
    }

    return 0;
}
