#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <iostream>
#include <any>
#include <memory>
#include <vector>
#include <variant>
  
enum TokenType {
  EMPTY_TOKEN,
  OPERATOR_TOKEN,
  ATOM_TOKEN,
};

enum OperationType {
  UNARY_OPERATION,
  BINARY_OPERATION,
  TERNARY_OPERATION,
  ARGUMENTS_OPERATION,
};

enum OperatorType {
  NONE_OPERATOR,
  
  ADD_OPERATOR,
  SUBTRACT_OPERATOR,
  MULTIPLY_OPERATOR,
  DIVIDE_OPERATOR,
  POWER_OPERATOR,
  
  NOT_OPERATOR,
  AND_OPERATOR,
  OR_OPERATOR,
  
  EQUAL_OPERATOR,
  NOT_EQUAL_OPERATOR,
  LOWER_EQUAL_OPERATOR,
  GREATER_EQUAL_OPERATOR,
  LOWER_OPERATOR,
  GREATER_OPERATOR,
  
  NUM_OPERATOR_TYPES
};

#include "atom.h"
#include "atom_list.h"
#include "token.h"

template <class A>
class TokenListBase {
public:
  virtual Token<A> get_left() = 0;
  virtual Token<A> get_right() = 0;
  virtual void put_left(Token<A> t) = 0;
  virtual void put_right(Token<A> t) = 0;
  virtual void print(bool details=false) = 0;
};

static std::string trim(const std::string& str, const std::string& whitespace = " \t") {
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

#include "expression.h"
#include "operators.h"
#include "operator_list.h"
#include "step_list.h"
#include "token_list.h"
#include "solver.h"

#endif // MAIN_H
