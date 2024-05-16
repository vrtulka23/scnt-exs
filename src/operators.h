#ifndef OPERATORS_H
#define OPERATORS_H

#include <stdexcept>

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
  virtual void operate_unary(TokenListBase *tokens) {throw std::logic_error("Unary operation is not implemented");};
  virtual void operate_binary(TokenListBase *tokens) {throw std::logic_error("Binary operation is not implemented");};
  virtual void operate_ternary(TokenListBase *tokens) {throw std::logic_error("Ternary operation is not implemented");};
  virtual void operate_arguments(TokenListBase *tokens) {throw std::logic_error("Argument operation is not implemented");};
  virtual void print() {};
};

class OperatorAdd: public OperatorBase {
public:
  OperatorAdd(): OperatorBase("add", "+", ADD_OPERATOR) {}
  void operate_unary(TokenListBase *tokens);
  void operate_binary(TokenListBase *tokens);
};

class OperatorSubtract: public OperatorBase {
public:
  OperatorSubtract(): OperatorBase("sub", "-", SUBTRACT_OPERATOR) {}
  void operate_unary(TokenListBase *tokens);
  void operate_binary(TokenListBase *tokens);
};

class OperatorMultiply: public OperatorBase {
public:
  OperatorMultiply(): OperatorBase("mul", "*", MULTIPLY_OPERATOR) {}
  void operate_binary(TokenListBase *tokens);
};

class OperatorDivide: public OperatorBase {
public:
  OperatorDivide(): OperatorBase("div", "/", DIVIDE_OPERATOR) {}
  void operate_binary(TokenListBase *tokens);
};

class OperatorPower: public OperatorBase {
public:
  OperatorPower(): OperatorBase("pow", "**", POWER_OPERATOR) {}
  void operate_binary(TokenListBase *tokens);
};

#endif // OPERATORS_H
