#ifndef EXS_OPERATORS_H
#define EXS_OPERATORS_H

#include <stdexcept>

#include "settings.h"

namespace exs {

template <class A, typename S = EmptySettings>
class OperatorBase {
 public:
  std::string name;
  std::string symbol;
  int type;
  std::vector<std::string> groups;
  OperatorBase(std::string n, std::string s, int t): name(n), symbol(s), type(t) {};
  virtual ~OperatorBase() = default;
  virtual bool check(Expression &expr) {
    return expr.right.rfind(symbol, 0) == 0;
  }
  virtual void parse(Expression &expr) {
     if (expr.right.length()>0) {
       expr.remove(symbol);
     }  
  };
  virtual void operate_unary(TokenListBase<A>* tokens)   {throw std::logic_error("Unary operation is not implemented");};
  virtual void operate_binary(TokenListBase<A>* tokens)  {throw std::logic_error("Binary operation is not implemented");};
  virtual void operate_ternary(TokenListBase<A>* tokens) {throw std::logic_error("Ternary operation is not implemented");};
  virtual void operate_group(TokenListBase<A>* tokens)   {throw std::logic_error("Group operation is not implemented");};
  virtual void operate_unary(TokenListBase<A>* tokens, S* settings)   {operate_unary(tokens);};
  virtual void operate_binary(TokenListBase<A>* tokens, S* settings)  {operate_binary(tokens);};
  virtual void operate_ternary(TokenListBase<A>* tokens, S* settings) {operate_ternary(tokens);};
  virtual void operate_group(TokenListBase<A>* tokens, S* settings)   {operate_group(tokens);};
  virtual void print() {};
};

template <class A, typename S = EmptySettings>
class OperatorTernary: public OperatorBase<A, S> {
public:
  std::string symbol_other;
  OperatorTernary(
    std::string  n,
    std::string  s,
    std::string  so,
    int t
  ): OperatorBase<A, S>(n, s, t), symbol_other(so) {}
  virtual void parse(Expression &expr) override {
    this->groups.clear();
    expr.remove(this->symbol);
    bool closed = false;
    while (expr.right.length()>0) {
      if (expr.right.rfind(symbol_other, 0) == 0) {
        expr.remove(symbol_other);
        this->groups.push_back(expr.pop_left());
        closed = true;
        break;
      }
      expr.shift();
    }
    if (!closed) {
      throw std::logic_error("Incomplete ternary operator: "+expr.expr);
    }
  };
};
  
template <class A, int N=0, typename S = EmptySettings>
class OperatorGroup: public OperatorBase<A, S> {
public:
  size_t num_groups            = N;
  std::string symbol_open;
  std::string symbol_close;
  std::string symbol_separator;
  OperatorGroup(const std::string n, const std::string  s, const int t):
    OperatorBase<A, S>(n, s, t), symbol_open("("), symbol_close(")"), symbol_separator(",") {}
  OperatorGroup(const std::string n, const std::string  s, const int t, const std::string so, const std::string sc):
    OperatorBase<A, S>(n, s, t), symbol_open(so), symbol_close(sc), symbol_separator(",") {}
  OperatorGroup(const std::string n, const std::string  s, const int t, const std::string so, const std::string sc, const std::string ss):
    OperatorBase<A, S>(n, s, t), symbol_open(so), symbol_close(sc), symbol_separator(ss) {}
  virtual void parse(Expression &expr) override {
    this->groups.clear();
    expr.remove(this->symbol);
    int depth = 1;
    while (depth>0) {
      if (expr.right.length()==0) {
        throw std::logic_error("Unclosed parentheses: "+expr.expr);
      } else if (expr.right.rfind(this->symbol, 0) == 0 || expr.right.rfind(symbol_open, 0) == 0) {
        depth++;
      } else if (expr.right.rfind(symbol_separator, 0) == 0 && depth==1) {
        expr.remove(symbol_separator);
        this->groups.push_back(expr.pop_left());
      } else if (expr.right.rfind(symbol_close, 0) == 0) {
        depth--;
        if (depth==0) {
          expr.remove(symbol_close);
          this->groups.push_back(expr.pop_left());
          break;
        }
      }
      expr.shift();
    }
    num_groups = this->groups.size();
    if (N>0 && num_groups!=N) {
      throw std::logic_error("Wrong number of group members: "+std::to_string(this->groups.size())+", "+std::to_string(N));
    }
  };
  virtual void operate_group(TokenListBase<A>* tokens) override {};  // this should stay empty
  virtual void operate_group(TokenListBase<A>* tokens, S* settings) override {operate_group(tokens);};
};

}
  
#include "math/add.h"
#include "math/subtract.h"
#include "math/multiply.h"
#include "math/divide.h"
#include "math/power.h"
#include "math/modulo.h"
#include "math/exponent.h"
#include "math/logarithm.h"
#include "math/logarithm_10.h"
#include "math/logarithm_base.h"
#include "math/power_base.h"
#include "math/square_root.h"
#include "math/sinus.h"
#include "math/cosinus.h"
#include "math/tangens.h"

#include "comparison/equal.h"
#include "comparison/not_equal.h"
#include "comparison/lower_equal.h"
#include "comparison/greater_equal.h"
#include "comparison/lower.h"
#include "comparison/greater.h"

#include "logical/not.h"
#include "logical/and.h"
#include "logical/or.h"

#include "branching/condition.h"
#include "branching/parentheses.h"

#endif // EXS_OPERATORS_H
