#ifndef SOLVER_FACTORY_H
#define SOLVER_FACTORY_H

#include <memory>
#include <string>
#include "solver.h"
#include "dp_solver.h"
#include "dijkstra_solver.h"

class SolverFactory {
public:
    static std::unique_ptr<Solver> createSolver(const std::string& solverType) {
        if (solverType == "dp") {
            return std::make_unique<DPSolver>();
        } else if (solverType == "dijkstra") {
            return std::make_unique<DijkstraSolver>();
        } else {
            throw std::runtime_error("Error: Unknown solver type.");
        }
    }
};

#endif
