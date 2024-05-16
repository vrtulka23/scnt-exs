#include <gtest/gtest.h>
#include <memory>

#include "../src/main.h"

// Initialization of the Soler
TEST(Solver, SolvingExpression) {
    
    Solver<AtomBase> solver;
    
    AtomBase atom = solver.solve("1.2 + 34");
    EXPECT_EQ(std::get<float>(atom.value), (float)35.2);

    atom = solver.solve("32 - 34");
    EXPECT_EQ(std::get<float>(atom.value), (float)-2);
    
    atom = solver.solve("32 * 2");
    EXPECT_EQ(std::get<float>(atom.value), (float)64);
    
    atom = solver.solve("32.4 / 2");
    EXPECT_EQ(std::get<float>(atom.value), (float)16.2);
    
    atom = solver.solve("3 ** 3");
    EXPECT_EQ(std::get<float>(atom.value), (float)27);
    
    atom = solver.solve("1.2 + +68/2 - -2**5 * 93");
    EXPECT_EQ(std::get<float>(atom.value), (float)3011.2);
}

TEST(Solver, CustomSteps) {
    
    // create custom step list
    StepList steps;
    steps.append(UNARY_OPERATION,  {ADD_OPERATOR});
    steps.append(BINARY_OPERATION, {MULTIPLY_OPERATOR});
    steps.append(BINARY_OPERATION, {ADD_OPERATOR});
    
    // test the solver
    Solver<AtomBase> solver(steps);
    AtomBase atom = solver.solve("1.2 + 5 * 4");
    EXPECT_EQ(std::get<float>(atom.value), (float)21.2);
}

TEST(Solver, CustomOperators) {
    
    // create custom operator list
    OperatorList operators;
    operators.append(ADD_OPERATOR,      std::make_shared<OperatorAdd>());
    operators.append(MULTIPLY_OPERATOR, std::make_shared<OperatorMultiply>());

    // test the solver
    Solver<AtomBase> solver(operators);
    AtomBase atom = solver.solve("1.2 + 5 * 4");
    EXPECT_EQ(std::get<float>(atom.value), (float)21.2);
}