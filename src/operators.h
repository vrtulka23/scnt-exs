#ifndef OPERATORS_H
#define OPERATORS_H

class OperatorInterface {
 public:
  std::string name;
  std::string symbol;
  OperatorType type;
  OperatorInterface(std::string n, std::string s, OperatorType t): name(n), symbol(s), type(t) {};
  virtual ~OperatorInterface() = default;
  virtual void operate_unary(TokenListInterface *tokens) {};
  virtual void operate_binary(TokenListInterface *tokens) {};
  virtual void operate_arguments(TokenListInterface *tokens) {};
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
