#include <gtest/gtest.h>
#include "../src/main.h"

// Initialization of the SolerClass
TEST(Solver, SolvingExpression) {
    
    SolverClass solver;
    
    solver.solve("1.2 + 34 - 32 * 93");
    
    //EXPECT_EQ(e.left, "");
}
