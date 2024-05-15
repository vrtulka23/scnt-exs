#ifndef OPERATORS_H
#define OPERATORS_H

#include <stdexcept>

class OperatorInterface {
 public:
  std::string name;
  std::string symbol;
  OperatorType type;
  OperatorInterface(std::string n, std::string s, OperatorType t): name(n), symbol(s), type(t) {};
  virtual ~OperatorInterface() = default;
  virtual void parse(Expression &expr) {
     if (expr.right.length()>0) {
       expr.remove(symbol);
     }  
  };
  virtual void operate_unary(TokenListInterface *tokens) {throw std::logic_error("Function not yet implemented");};
  virtual void operate_binary(TokenListInterface *tokens) {throw std::logic_error("Function not yet implemented");};
  virtual void operate_arguments(TokenListInterface *tokens) {throw std::logic_error("Function not yet implemented");};
  virtual void print() {};
};

class OperatorAdd: public OperatorInterface {
public:
  OperatorAdd(): OperatorInterface("add", "+", ADD_OPERATOR) {}
  void operate_unary(TokenListInterface *tokens);
  void operate_binary(TokenListInterface *tokens);
};

class OperatorSubtract: public OperatorInterface {
public:
  OperatorSubtract(): OperatorInterface("sub", "-", SUBTRACT_OPERATOR) {}
  void operate_unary(TokenListInterface *tokens);
  void operate_binary(TokenListInterface *tokens);
};

class OperatorMultiply: public OperatorInterface {
public:
  OperatorMultiply(): OperatorInterface("mul", "*", MULTIPLY_OPERATOR) {}
  void operate_unary(TokenListInterface *tokens);
};

class OperatorDivide: public OperatorInterface {
public:
  OperatorDivide(): OperatorInterface("div", "/", DIVIDE_OPERATOR) {}
  void operate_unary(TokenListInterface *tokens);
};

#endif // OPERATORS_H
