#include <math.h>

#include "../main.h"

void OperatorPower::operate_binary(TokenListBase *tokens) {
  Token left = tokens->get_left();
  Token right = tokens->get_right();
  left.atom->value = pow(left.atom->value, right.atom->value);
  tokens->put_left(left);
}
