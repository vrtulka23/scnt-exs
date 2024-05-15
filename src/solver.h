#ifndef SOLVER_H
#define SOLVER_H

#include <memory>

class SolverClass {
public:
    OperatorListClass operators;
    SolverClass() {};
    SolverClass(OperatorListClass &o): operators(o) {};
    void solve(std::string expression);
};

#endif // SOLVER_H