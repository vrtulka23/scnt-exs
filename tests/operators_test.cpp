#include <gtest/gtest.h>
#include <memory>

#include "../src/main.h"

// Initialization of the operators map
TEST(Operators, Initialization) {

  OperatorList<Atom> operators;
  operators.append(ADD_OPERATOR,      std::make_shared<OperatorAdd<Atom>>());
  operators.append(SUBTRACT_OPERATOR, std::make_shared<OperatorSubtract<Atom>>());
  
  OperatorBase<Atom> *op = operators.select(ADD_OPERATOR);
  EXPECT_EQ(op->type, ADD_OPERATOR);

  op = operators.select(SUBTRACT_OPERATOR);
  EXPECT_EQ(op->type, SUBTRACT_OPERATOR);
}

TEST(Operators, CustomOperatorsList) {

  // initialize operators
  OperatorList<Atom> operators;
  operators.append(ADD_OPERATOR,      std::make_shared<OperatorAdd<Atom>>());
  operators.append(MULTIPLY_OPERATOR, std::make_shared<OperatorMultiply<Atom>>());
  
  OperatorBase<Atom> *op = operators.select(MULTIPLY_OPERATOR);
  EXPECT_EQ(op->type, MULTIPLY_OPERATOR);
  
}

TEST(Operators, OperatorAdd) {

  OperatorList<Atom> operators;
  operators.append(ADD_OPERATOR, std::make_shared<OperatorAdd<Atom>>());

  // prepare tokens
  TokenList<Atom> tokens(&operators);
  tokens.append(OPERATOR_TOKEN, ADD_OPERATOR);
  tokens.append(OPERATOR_TOKEN, ADD_OPERATOR);
  tokens.append(ATOM_TOKEN,     "3.4");
  //tokens.print(true);

  // extract first token on the right
  Token token = tokens.get_right();

  // get an operator and perform unary operation on the remaining tokens
  OperatorBase<Atom> *op = operators.select(ADD_OPERATOR);
  //tokens.print(true);
  op->operate_unary(&tokens);
  //tokens.print(true);
}

TEST(Operators, OpearateAdd) {

  OperatorList<Atom> operators;
  operators.append(ADD_OPERATOR, std::make_shared<OperatorAdd<Atom>>());

  // prepare tokens
  TokenList<Atom> tokens(&operators);
  tokens.append(OPERATOR_TOKEN, ADD_OPERATOR);
  tokens.append(OPERATOR_TOKEN, ADD_OPERATOR);
  tokens.append(ATOM_TOKEN,     "3.4");
  //tokens.print(true);

  // create operator list
  std::vector<OperatorType> oper = {ADD_OPERATOR};
  OperatorBase<Atom> *op = operators.select(ADD_OPERATOR);
  
  // operate on tokens
  tokens.operate(oper, UNARY_OPERATION);
  //tokens.print(true);
}
