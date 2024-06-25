#ifndef SOLVER_H
#define SOLVER_H

#include "point.h"
#include <vector>

class Solver {
public:
    virtual ~Solver() = default;
    virtual double solve(const std::vector<Point>& points) const = 0;
};

#endif 
