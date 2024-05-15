#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class TokenClass {
public:
  TokenType type;
  OperatorType optype;
  AtomInterface *atom;
  TokenClass(TokenType t);
  TokenClass(TokenType t, OperatorType o);
  TokenClass(TokenType t, AtomClass *a);
  TokenClass operator+();
  TokenClass operator+(TokenClass &other);
  TokenClass operator-();
  TokenClass operator-(TokenClass &other);
  void print();
};

#endif //TOKEN
