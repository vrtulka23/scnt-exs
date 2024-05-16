#include "main.h"

TokenClass::TokenClass(TokenType t): type(t), atom(NULL) {};

TokenClass::TokenClass(TokenType t, OperatorType o): type(t), optype(o), atom(NULL) {};

TokenClass::TokenClass(TokenType t, AtomBase *a): type(t), atom(a) {};

void TokenClass::print() {
  if (type==EMPTY_TOKEN) {
    std::cout << "Token(EMPTY)" << std::endl;
  } else if (type==OPERATOR_TOKEN) {
    std::cout << "Token(OPERATOR " << optype << ")" << std::endl;
  } else if (type==ATOM_TOKEN) {
    std::cout << "Token(ATOM " << atom << ")" << std::endl;
  }
}
