#ifndef DIJKSTRA_SOLVER_H
#define DIJKSTRA_SOLVER_H

#include "solver.h"

class DijkstraSolver : public Solver {
public:
    double solve(const std::vector<Point>& points) const override;
};

#endif 
