#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <iostream>
#include <any>
#include <memory>
#include <vector>

enum TokenType {
  EMPTY_TOKEN,
  OPERATOR_TOKEN,
  ATOM_TOKEN,
};

enum OperationType {
  UNARY_OPERATION,
  BINARY_OPERATION,
  ARGUMENTS_OPERATION,
};

enum OperatorType {
  NONE_OPERATOR,
  ADD_OPERATOR,
  SUBTRACT_OPERATOR,
  MULTIPLY_OPERATOR,
  DIVIDE_OPERATOR,
  NUM_OPERATOR_TYPES
};

class AtomInterface {
public:
  float value;
  AtomInterface(std::string v): value(std::stof(v)) {};
  ~AtomInterface() {};
};

typedef AtomInterface AtomClass; // temporary alias, AtomClass should be defined by user

#include "atom_list.h"
#include "token.h"

class TokenListInterface {
public:
  virtual TokenClass get_left() = 0;
  virtual TokenClass get_right() = 0;
  virtual void put_left(TokenClass t) = 0;
  virtual void put_right(TokenClass t) = 0;
  virtual void print(bool details=false) = 0;
};

#include "operators.h"
#include "operator_list.h"
#include "token_list.h"

static std::string trim(const std::string& str, const std::string& whitespace = " \t") {
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

class Expression {
public:
  std::string left;  // left side
  std::string right; // right side
  std::string expr;  // original expression
  Expression(std::string expression);
  void shift(int nchar);
  void remove(std::string string);
  std::string pop_left();
  void print();
};

#endif // MAIN_H
