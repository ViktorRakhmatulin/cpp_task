#ifndef DIJKSTRA_SOLVER_H
#define DIJKSTRA_SOLVER_H

#include "solver.h"

class DijkstraSolver : public Solver {
    /**
     * @brief Solves the shortest path problem using Dijkstra's algorithm.
     * 
     * @param points Vector of points representing the path.
     * @return double The shortest travel time computed.
     */
public:
    double solve(const std::vector<Point>& points) const override;
    std::string solver_description() const override { return "Dijkstra Solver"; }

};

#endif 
