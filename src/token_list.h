#ifndef TOKEN_LIST_H
#define TOKEN_LIST_H

#include <deque>
#include <algorithm>
#include <vector>
#include <stdexcept>

class TokenListClass: public TokenListInterface {
public:
  std::deque<TokenClass> left;
  std::deque<TokenClass> right;
  void append(const TokenClass &t);
  TokenClass get_left();
  TokenClass get_right();
  void put_left(TokenClass t);
  void put_right(TokenClass t);
  void operate(const std::vector<OperatorType> &ops, OperationType oitype);
  void print(bool details);
private:
  void print_details(std::deque<TokenClass>::iterator i);
};
  
#endif // TOKEN_LIST_H
