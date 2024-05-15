#include "main.h"

TokenClass::TokenClass(TokenType t): type(t), atom(NULL) {};

TokenClass::TokenClass(TokenType t, OperatorType o): type(t), optype(o), atom(NULL) {};

TokenClass::TokenClass(TokenType t, AtomInterface *a): type(t), atom(a) {};

TokenClass TokenClass::operator+() {
  return *this;
}

TokenClass TokenClass::operator+(TokenClass &other) {
  return *this;
}

TokenClass TokenClass::operator-() {
  return *this;
}

TokenClass TokenClass::operator-(TokenClass &other) {
  return *this;
}

TokenClass TokenClass::operator*(TokenClass &other) {
  return *this;
}

TokenClass TokenClass::operator/(TokenClass &other) {
  return *this;
}

void TokenClass::print() {
  if (type==EMPTY_TOKEN) {
    std::cout << "Token(EMPTY)" << std::endl;
  } else if (type==OPERATOR_TOKEN) {
    std::cout << "Token(OPERATOR " << optype << ")" << std::endl;
  } else if (type==ATOM_TOKEN) {
    std::cout << "Token(ATOM " << atom << ")" << std::endl;
  }
}
