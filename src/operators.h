#ifndef OPERATORS_H
#define OPERATORS_H

#include <stdexcept>

template <class A>
class OperatorBase {
 public:
  std::string name;
  std::string symbol;
  OperatorType type;
  std::vector<std::string> args;
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

#include "math/add.h"
#include "math/subtract.h"
#include "math/multiply.h"
#include "math/divide.h"
#include "math/power.h"

#include "comparison/equal.h"
#include "comparison/not_equal.h"
#include "comparison/lower_equal.h"
#include "comparison/greater_equal.h"
#include "comparison/lower.h"
#include "comparison/greater.h"

#include "logical/not.h"
#include "logical/and.h"
#include "logical/or.h"

template <class A, int N=1>
class OperatorArguments: public OperatorBase<A> {
public:
  std::string symbol_open      = "(";
  std::string symbol_separator = ",";
  std::string symbol_close     = ")";
  OperatorArguments(
    std::string  n,
    std::string  s,
    OperatorType t
  ): OperatorBase<A>(n, s, t) {}
  virtual void parse(Expression &expr) {
    this->args.clear();
    if (expr.right.length()>0) {
      expr.remove(this->symbol);
    }
    int depth = 1;
    while (depth>0) {
      if (expr.right.length()==0) {
        throw std::logic_error("Unclosed parentheses: "+expr.expr);
      } else if (expr.right.rfind(this->symbol, 0) == 0 || expr.right.rfind(symbol_open, 0) == 0) {
        depth++;
      } else if (expr.right.rfind(symbol_separator, 0) == 0 && depth==1) {
        expr.remove(symbol_separator);
        this->args.push_back(expr.pop_left());
      } else if (expr.right.rfind(symbol_close, 0) == 0) {
        depth--;
        if (depth==0) {
          expr.remove(symbol_close);
          this->args.push_back(expr.pop_left());
          break;
        }
      }
      expr.shift();
    }
    if (this->args.size()!=N) {
      throw std::logic_error("Wrong number of arguments: "+std::to_string(this->args.size())+", "+std::to_string(N));
    }
  };
  void operate_arguments(TokenListBase<A> *tokens) {};
};

#include "arguments/parentheses.h"
#include "arguments/exponent.h"

#endif // OPERATORS_H
