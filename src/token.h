#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class TokenClass {
public:
  TokenType type;
  OperatorType optype;
  AtomClass *atom;
  TokenClass(TokenType t);
  TokenClass(TokenType t, OperatorType o);
  TokenClass(TokenType t, std::string a);
  TokenClass operator+();
  TokenClass operator+(TokenClass &other);
  TokenClass operator-();
  TokenClass operator-(TokenClass &other);
  void print();
};

#endif //TOKEN
