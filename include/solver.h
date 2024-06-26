#ifndef SOLVER_H
#define SOLVER_H

#include "point.h"
#include <vector>
#include <string>
class Solver {
public:
    virtual ~Solver() = default;
    virtual double solve(const std::vector<Point>& points) const = 0;
    virtual std::string solver_description() const = 0;
};

#endif 
