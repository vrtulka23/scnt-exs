#include <gtest/gtest.h>
#include <memory>

#include "../src/main.h"

// Initialization of the operators map
TEST(Operators, Initialization) {

  OperatorList operators;
  operators.append(ADD_OPERATOR,      std::make_shared<OperatorAdd>());
  operators.append(SUBTRACT_OPERATOR, std::make_shared<OperatorSubtract>());
  
  OperatorBase *op = operators.select(ADD_OPERATOR);
  EXPECT_EQ(op->type, ADD_OPERATOR);

  op = operators.select(SUBTRACT_OPERATOR);
  EXPECT_EQ(op->type, SUBTRACT_OPERATOR);
}

TEST(Operators, CustomOperatorsList) {

  // initialize operators
  OperatorList operators;
  operators.append(ADD_OPERATOR,      std::make_shared<OperatorAdd>());
  operators.append(MULTIPLY_OPERATOR, std::make_shared<OperatorMultiply>());
  
  OperatorBase *op = operators.select(MULTIPLY_OPERATOR);
  EXPECT_EQ(op->type, MULTIPLY_OPERATOR);
  
}

TEST(Operators, OperatorAdd) {

  OperatorList operators;
  operators.append(ADD_OPERATOR, std::make_shared<OperatorAdd>());

  // prepare tokens
  TokenList<Atom> tokens(&operators);
  tokens.append(OPERATOR_TOKEN, ADD_OPERATOR);
  tokens.append(OPERATOR_TOKEN, ADD_OPERATOR);
  Atom a("3.4");
  tokens.append(ATOM_TOKEN,     &a);
  //tokens.print(true);

  // extract first token on the right
  Token token = tokens.get_right();

  // get an operator and perform unary operation on the remaining tokens
  OperatorBase *op = operators.select(ADD_OPERATOR);
  //tokens.print(true);
  op->operate_unary(&tokens);
  //tokens.print(true);
}

TEST(Operators, OpearateAdd) {

  OperatorList operators;
  operators.append(ADD_OPERATOR, std::make_shared<OperatorAdd>());

  // prepare tokens
  TokenList<Atom> tokens(&operators);
  tokens.append(OPERATOR_TOKEN, ADD_OPERATOR);
  tokens.append(OPERATOR_TOKEN, ADD_OPERATOR);
  Atom a("3.4");
  tokens.append(ATOM_TOKEN,     &a);
  //tokens.print(true);

  // create operator list
  std::vector<OperatorType> oper = {ADD_OPERATOR};
  OperatorBase *op = operators.select(ADD_OPERATOR);
  
  // operate on tokens
  tokens.operate(oper, UNARY_OPERATION);
  //tokens.print(true);
}
