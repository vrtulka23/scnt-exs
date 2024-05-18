#include <gtest/gtest.h>
#include <memory>

#include "../src/main.h"

// Basic mathematic expressions
TEST(Solver, SolvingMath) {
    
    Solver<Atom> solver;
    
    Atom atom = solver.solve("1.2 + 34");
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

// Basic comparison expressions
TEST(Solver, SolvingComparison) {
    
    Solver<Atom> solver;
    
    Atom atom = solver.solve("23 == 34");
    EXPECT_EQ(std::get<bool>(atom.value), false);
    atom = solver.solve("23.2 == 23.2");
    EXPECT_EQ(std::get<bool>(atom.value), true);
    
    atom = solver.solve("23 != 34");
    EXPECT_EQ(std::get<bool>(atom.value), true);
    atom = solver.solve("23.2 != 23.2");
    EXPECT_EQ(std::get<bool>(atom.value), false);
    
    atom = solver.solve("23 <= 34");
    EXPECT_EQ(std::get<bool>(atom.value), true);
    atom = solver.solve("34 <= 23");
    EXPECT_EQ(std::get<bool>(atom.value), false);
    atom = solver.solve("23 <= 23");
    EXPECT_EQ(std::get<bool>(atom.value), true);
    
    atom = solver.solve("23 >= 34");
    EXPECT_EQ(std::get<bool>(atom.value), false);
    atom = solver.solve("34 >= 23");
    EXPECT_EQ(std::get<bool>(atom.value), true);
    atom = solver.solve("23 >= 23");
    EXPECT_EQ(std::get<bool>(atom.value), true);
    
    atom = solver.solve("23 < 34");
    EXPECT_EQ(std::get<bool>(atom.value), true);
    atom = solver.solve("34.2 < 23.2");
    EXPECT_EQ(std::get<bool>(atom.value), false);
    
    atom = solver.solve("23 > 34");
    EXPECT_EQ(std::get<bool>(atom.value), false);
    atom = solver.solve("34.2 > 23.2");
    EXPECT_EQ(std::get<bool>(atom.value), true);
}

// Basic logical expressions
TEST(Solver, SolvingLogical) {
    
    Solver<Atom> solver;
    
    Atom atom = solver.solve("!true");
    EXPECT_EQ(std::get<bool>(atom.value), false);
    atom = solver.solve("!false");
    EXPECT_EQ(std::get<bool>(atom.value), true);
    
    atom = solver.solve("false && true");
    EXPECT_EQ(std::get<bool>(atom.value), false);
    atom = solver.solve("true && true");
    EXPECT_EQ(std::get<bool>(atom.value), true);
    
    atom = solver.solve("false || true");
    EXPECT_EQ(std::get<bool>(atom.value), true);
    atom = solver.solve("false || false");
    EXPECT_EQ(std::get<bool>(atom.value), false);
}

// Basic argument expressions
TEST(Solver, SolvingGroups) {
    
    Solver<Atom> solver;
    
    Atom atom = solver.solve("(1+2)-3");
    EXPECT_EQ(std::get<float>(atom.value), (float)0);
    
    atom = solver.solve("exp(1+2)-3");
    EXPECT_EQ(std::get<float>(atom.value), (float)17.085536923187668);
    
    atom = solver.solve("log(1+2)-3");
    EXPECT_EQ(std::get<float>(atom.value), (float)-1.9013877113318902);
    
    atom = solver.solve("log10(1+2)-3");
    EXPECT_EQ(std::get<float>(atom.value), (float)-2.5228787452803374);
    
    atom = solver.solve("logb(1+2,2)-3");
    EXPECT_EQ(std::get<float>(atom.value), (float)-1.4150374992788437);
    
    atom = solver.solve("powb(2,3)-3");
    EXPECT_EQ(std::get<float>(atom.value), (float)5);
    
    atom = solver.solve("sqrt(16)-3");
    EXPECT_EQ(std::get<float>(atom.value), (float)1);
    
    atom = solver.solve("sin(16)-3");
    EXPECT_EQ(std::get<float>(atom.value), (float)-3.2879033166650653);
    
    atom = solver.solve("cos(16)-3");
    EXPECT_EQ(std::get<float>(atom.value), (float)-3.9576594803233847);
    
    atom = solver.solve("tan(16)-3");
    EXPECT_EQ(std::get<float>(atom.value), (float)-2.6993677579760966);
    
    // nested argument operators
    atom = solver.solve("exp(1+(5-3))-3");
    EXPECT_EQ(std::get<float>(atom.value), (float)17.085536923187668);
}
    
// Conditional operator
TEST(Solver, SolvingCondition) {
    
    Solver<Atom> solver;
    
    Atom atom = solver.solve("(true ? 2 : 3)-3");
    EXPECT_EQ(std::get<float>(atom.value), (float)-1);
    
    atom = solver.solve("(false ? 2 : 3)-3");
    EXPECT_EQ(std::get<float>(atom.value), (float)-0);
    
    atom = solver.solve("((2==3) ? 2 : 3)-3");
    EXPECT_EQ(std::get<float>(atom.value), (float)-0);
}

TEST(Solver, CustomSteps) {
    
    // create custom step list
    StepList steps;
    steps.append(UNARY_OPERATION,  {ADD_OPERATOR});
    steps.append(BINARY_OPERATION, {MULTIPLY_OPERATOR});
    steps.append(BINARY_OPERATION, {ADD_OPERATOR});
    
    // test the solver
    Solver<Atom> solver(steps);
    Atom atom = solver.solve("1.2 + 5 * 4");
    EXPECT_EQ(std::get<float>(atom.value), (float)21.2);
}

TEST(Solver, CustomOperators) {
    
    // create custom operator list
    OperatorList<Atom> operators;
    operators.append(ADD_OPERATOR,      std::make_shared<OperatorAdd<Atom>>());
    operators.append(MULTIPLY_OPERATOR, std::make_shared<OperatorMultiply<Atom>>());
    operators.append(POWER_OPERATOR,    std::make_shared<OperatorPower<Atom>>("^")); // changin the symbol

    // test the solver
    Solver<Atom> solver(operators);
    Atom atom = solver.solve("1.2 + 5 * 2^2");
    EXPECT_EQ(std::get<float>(atom.value), (float)21.2);
}