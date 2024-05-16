#include "../main.h"

void OperatorDivide::operate_binary(TokenListBase *tokens) {
  Token left = tokens->get_left();
  Token right = tokens->get_right();
  left.atom->value /= right.atom->value;
  tokens->put_left(left);
}
