#ifndef DP_SOLVER_H
#define DP_SOLVER_H

#include "solver.h"

class DPSolver : public Solver {
public:
    double solve(const std::vector<Point>& points) const override;
};

#endif // DP_SOLVER_H
