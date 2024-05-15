#ifndef SOLVER_H
#define SOLVER_H

#include <memory>

typedef std::vector<std::pair<OperationType, std::vector<OperatorType>>> StepListType;

class SolverClass {
public:
    OperatorListClass operators;
    StepListType steps;
    SolverClass() {init_steps();};
    SolverClass(OperatorListClass &o): operators(o) {init_steps();};
    SolverClass(StepListType &s): steps(s) {};
    SolverClass(OperatorListClass &o, StepListType &s): operators(o), steps(s) {};
    AtomInterface solve(std::string expression);
private:
    void init_steps() {
        steps.push_back({UNARY_OPERATION,  {ADD_OPERATOR, SUBTRACT_OPERATOR}});
        steps.push_back({BINARY_OPERATION, {POWER_OPERATOR}});
        steps.push_back({BINARY_OPERATION, {MULTIPLY_OPERATOR, DIVIDE_OPERATOR}});
        steps.push_back({BINARY_OPERATION, {ADD_OPERATOR, SUBTRACT_OPERATOR}});
    }
};

#endif // SOLVER_H