#include <gtest/gtest.h>
#include "../src/main.h"

// Initialization of the operators map
TEST(Operators, Initialization) {

  OperatorListClass operators;
  
  OperatorInterface *op = operators.find(ADD_OPERATOR);
  EXPECT_EQ(op->type, ADD_OPERATOR);

  op = operators.find(SUBTRACT_OPERATOR);
  EXPECT_EQ(op->type, SUBTRACT_OPERATOR);
}

TEST(Operators, CustomOperatorsList) {

  // create custom operator list
  OperatorsType map;
  map[ADD_OPERATOR] = new OperatorAdd();
  map[MULTIPLY_OPERATOR] = new OperatorMultiply();

  // initialize operator map
  OperatorListClass operators(map);
  OperatorInterface *op = operators.find(MULTIPLY_OPERATOR);
  EXPECT_EQ(op->type, MULTIPLY_OPERATOR);
  
}

TEST(Operators, OperatorAdd) {

  // prepare tokens
  TokenListClass tokens;
  tokens.append(TokenClass(OPERATOR_TOKEN, ADD_OPERATOR));
  tokens.append(TokenClass(OPERATOR_TOKEN, ADD_OPERATOR));
  tokens.append(TokenClass(ATOM_TOKEN,     "3.4"));
  tokens.print(true);

  // extract first token on the right
  TokenClass token = tokens.get_right();

  // get an operator and perform unary operation on the remaining tokens
  OperatorInterface *op = OperatorList.find(ADD_OPERATOR);
  tokens.print(true);
  op->operate_unary(&tokens);
  tokens.print(true);
}

TEST(Operators, OpearateAdd) {

  // prepare tokens
  TokenListClass tokens;
  tokens.append(TokenClass(OPERATOR_TOKEN, ADD_OPERATOR));
  tokens.append(TokenClass(OPERATOR_TOKEN, ADD_OPERATOR));
  tokens.append(TokenClass(ATOM_TOKEN,     "3.4"));
  tokens.print(true);

  // create operator list
  std::vector<OperatorType> operators = {ADD_OPERATOR};
  OperatorInterface *op = OperatorList.find(ADD_OPERATOR);
  
  // operate on tokens
  tokens.operate(operators, UNARY_OPERATION);
  tokens.print(true);
}
