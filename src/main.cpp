#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <limits>
#include <stdexcept>
#include "point.h"
#include "utilities.h"
#include "solver.h"
#include "dp_solver.h"
#include "dijkstra_solver.h"
#include "config.h"
#include "solver_factory.h"

int main()
{
    int n;
    double result;

    std::unique_ptr<Solver> solver;
    try
    {
        std::string solver_type = Config::read_solver_from_config("config.json");
        solver = SolverFactory::create_solver(solver_type);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    while (true)
    {
        std::cout << "Enter N (0 to exit): ";
        if (!(std::cin >> n))
        {
            std::cerr << "Error: Invalid input for N. Please enter a numeric value.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (n == 0)
        {
            break;
        }

        int totalPoints = n + 2;
        std::vector<Point> points = read_points(n);
        if (points.size() != totalPoints)
        {
            continue;
        }

        result = solver->solve(points);

        std::cout << std::fixed << std::setprecision(3) 
        << "Shortest travel time (" << solver->solver_description() << "): " << result << std::endl;
    }

    return 0;
}