#ifndef OPERATORS_H
#define OPERATORS_H

#include <stdexcept>

template <class A>
class OperatorBase {
 public:
  std::string name;
  std::string symbol;
  OperatorType type;
  OperatorBase(std::string n, std::string s, OperatorType t): name(n), symbol(s), type(t) {};
  virtual ~OperatorBase() = default;
  virtual void parse(Expression &expr) {
     if (expr.right.length()>0) {
       expr.remove(symbol);
     }  
  };
  virtual void operate_unary(TokenListBase<A> *tokens) {throw std::logic_error("Unary operation is not implemented");};
  virtual void operate_binary(TokenListBase<A> *tokens) {throw std::logic_error("Binary operation is not implemented");};
  virtual void operate_ternary(TokenListBase<A> *tokens) {throw std::logic_error("Ternary operation is not implemented");};
  virtual void operate_arguments(TokenListBase<A> *tokens) {throw std::logic_error("Argument operation is not implemented");};
  virtual void print() {};
};

#include "operators/add.h"
#include "operators/subtract.h"
#include "operators/multiply.h"
#include "operators/divide.h"
#include "operators/power.h"

#include "operators/equal.h"
#include "operators/not_equal.h"
#include "operators/lower_equal.h"
#include "operators/greater_equal.h"
#include "operators/lower.h"
#include "operators/greater.h"

#endif // OPERATORS_H
