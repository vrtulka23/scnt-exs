#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
public:
  std::string left;  // left side
  std::string right; // right side
  std::string expr;  // original expression
  Expression(std::string expression);
  void shift(int nchar=1);
  void remove(std::string string);
  std::string pop_left();
  void print();
};

#endif // EXPRESSION_H
