#ifndef EXPRESSION_H
#define EXPRESSION_H

namespace exs {

class Expression {
public:
  std::string left;  // left side
  std::string right; // right side
  std::string expr;  // original expression
  Expression(std::string expression) {
    left  = "";
    right = expression;
    expr  = expression;
  };
  void shift(int nchar=1) {
    left  += right.substr(0,nchar);
    right =  right.substr(nchar,right.length());
  };
  void remove(std::string string) {
    right = right.substr(string.length(), right.length());
  };
  std::string pop_left() {
    std::string dummy = trim(left);
    left = "";
    return dummy;
  };
  void print() {
    std::cout << "Expression(L'" << left << "' R'" << right << "' E'" << expr << "')\n";
  };
};

}

#endif // EXPRESSION_H
