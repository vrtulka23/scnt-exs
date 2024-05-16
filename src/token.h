#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token {
public:
  TokenType type;
  OperatorType optype;
  AtomBase *atom;
  Token(TokenType t);
  Token(TokenType t, OperatorType o);
  Token(TokenType t, AtomBase *a);
  void print();
};

#endif //TOKEN
