#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class TokenClass {
public:
  TokenType type;
  OperatorType optype;
  AtomBase *atom;
  TokenClass(TokenType t);
  TokenClass(TokenType t, OperatorType o);
  TokenClass(TokenType t, AtomBase *a);
  void print();
};

#endif //TOKEN
