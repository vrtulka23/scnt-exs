#include <gtest/gtest.h>
#include "../src/main.h"

// Initialization of the Soler
TEST(Solver, SolvingExpression) {
    
    Solver<AtomBase> solver;
    
    AtomBase atom = solver.solve("1.2 + 34");
    EXPECT_EQ(atom.value, (float)35.2);

    atom = solver.solve("32 - 34");
    EXPECT_EQ(atom.value, (float)-2);
    
    atom = solver.solve("32 * 2");
    EXPECT_EQ(atom.value, (float)64);
    
    atom = solver.solve("32.4 / 2");
    EXPECT_EQ(atom.value, (float)16.2);
    
    atom = solver.solve("3 ** 3");
    EXPECT_EQ(atom.value, (float)27);
    
    atom = solver.solve("1.2 + +68/2 - -2**5 * 93");
    EXPECT_EQ(atom.value, (float)3011.2);
}

TEST(Solver, CustomSteps) {
    
    StepListType steps;
    steps.push_back({UNARY_OPERATION,  {ADD_OPERATOR}});
    steps.push_back({BINARY_OPERATION, {MULTIPLY_OPERATOR}});
    steps.push_back({BINARY_OPERATION, {ADD_OPERATOR}});
    
    Solver<AtomBase> solver(steps);

    AtomBase atom = solver.solve("1.2 + 5 * 4");
    EXPECT_EQ(atom.value, (float)21.2);
}

TEST(Solver, CustomOperators) {
    
    // create custom operator list
    OperatorListType map;
    map[ADD_OPERATOR] = new OperatorAdd();
    map[MULTIPLY_OPERATOR] = new OperatorMultiply();
    OperatorList operators(map);
    
    /*
    std::cout << "a" << std::endl;
    Solver<AtomBase> solver(operators);
    std::cout << "c" << std::endl;

    AtomBase atom = solver.solve("1.2 + 5 * 4");
    EXPECT_EQ(atom.value, (float)21.2);
    */
}