#include "../main.h"

void OperatorMultiply::operate_binary(TokenListBase *tokens) {
  TokenClass left = tokens->get_left();
  TokenClass right = tokens->get_right();
  left.atom->value *= right.atom->value;
  tokens->put_left(left);
}
