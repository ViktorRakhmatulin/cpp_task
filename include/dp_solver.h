#ifndef DP_SOLVER_H
#define DP_SOLVER_H

#include "solver.h"

class DPSolver : public Solver {
public:
    double solve(const std::vector<Point>& points) const override;
    std::string solver_description() const override { return "DP Solver"; } 
};

#endif 
