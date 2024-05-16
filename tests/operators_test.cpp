#include <gtest/gtest.h>
#include "../src/main.h"

// Initialization of the operators map
TEST(Operators, Initialization) {

  OperatorList operators;
  
  OperatorBase *op = operators.select(ADD_OPERATOR);
  EXPECT_EQ(op->type, ADD_OPERATOR);

  op = operators.select(SUBTRACT_OPERATOR);
  EXPECT_EQ(op->type, SUBTRACT_OPERATOR);
}

TEST(Operators, CustomOperatorsList) {

  // create custom operator list
  OperatorListType map;
  map[ADD_OPERATOR] = new OperatorAdd();
  map[MULTIPLY_OPERATOR] = new OperatorMultiply();

  // initialize operator map
  OperatorList operators(map);
  OperatorBase *op = operators.select(MULTIPLY_OPERATOR);
  EXPECT_EQ(op->type, MULTIPLY_OPERATOR);
  
}

TEST(Operators, OperatorAdd) {

  OperatorList operators;

  // prepare tokens
  TokenList tokens(&operators);
  tokens.append(OPERATOR_TOKEN, ADD_OPERATOR);
  tokens.append(OPERATOR_TOKEN, ADD_OPERATOR);
  AtomBase a("3.4");
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

  // prepare tokens
  TokenList tokens(&operators);
  tokens.append(OPERATOR_TOKEN, ADD_OPERATOR);
  tokens.append(OPERATOR_TOKEN, ADD_OPERATOR);
  AtomBase a("3.4");
  tokens.append(ATOM_TOKEN,     &a);
  //tokens.print(true);

  // create operator list
  std::vector<OperatorType> oper = {ADD_OPERATOR};
  OperatorBase *op = operators.select(ADD_OPERATOR);
  
  // operate on tokens
  tokens.operate(oper, UNARY_OPERATION);
  //tokens.print(true);
}
