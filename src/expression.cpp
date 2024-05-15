#import <iostream>
#include <string>
#include "main.h"

Expression::Expression(std::string expression) {
  left  = "";
  right = expression;
  expr  = expression;
}

void Expression::shift(int nchar) {
  left  += right.substr(0,nchar);
  right =  right.substr(nchar,right.length());
}

void Expression::remove(std::string string) {
  right = right.substr(string.length(), right.length());
}

std::string Expression::pop_left() {
  std::string dummy = trim(left);
  left = "";
  return dummy;
}

void Expression::print() {
  std::cout << "Expression(L'" << left << "' R'" << right << "' E'" << expr << "')" << std::endl;
}
