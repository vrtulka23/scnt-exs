#include <iostream>
#include <string>
#include "main.h"
#include "helpers.h"

Expression::Expression(std::string e) {
  expr = e;
  right = e;
  left = "";
}

void Expression::shift(int n) {
  left = left + right.substr(0, n);
  right = right.substr(n, right.length());
}

void Expression::remove(std::string s) {
  right = right.substr(s.length(), right.length());
}

std::string Expression::pop_left() {
  std::string s = trim(left);
  left = "";
  return s;
}

void Expression::print() {
  std::cout << expr << " L " << left << " R " << right << std::endl;
}
