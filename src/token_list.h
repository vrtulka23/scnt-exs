#ifndef TOKEN_LIST_H
#define TOKEN_LIST_H

#include <deque>
#include <algorithm>
#include <vector>
#include <stdexcept>

class TokenList: public TokenListBase {
public:
  std::deque<Token> left;
  std::deque<Token> right;
  OperatorList *operators;
  TokenList(OperatorList *o): operators(o) {};
  void append(TokenType t);
  void append(TokenType t, OperatorType o);
  void append(TokenType t, AtomBase *a);
  Token get_left();
  Token get_right();
  void put_left(Token t);
  void put_right(Token t);
  void operate(const std::vector<OperatorType> &ops, OperationType oitype);
  void print(bool details=false);
private:
  void print_details(std::deque<Token>::iterator i);
};
  
#endif // TOKEN_LIST_H
