#ifndef OPERATOR_POWER_H
#define OPERATOR_POWER_H

#include <math.h>

class OperatorPower: public OperatorBase {
public:
  OperatorPower(): OperatorBase("pow", "**", POWER_OPERATOR) {}
  void operate_binary(TokenListBase *tokens) {
    Token left = tokens->get_left();
    Token right = tokens->get_right();
    left.atom->value = pow(std::get<float>(left.atom->value), std::get<float>(right.atom->value));
    tokens->put_left(left);
  };
};

#endif // OPERATOR_POWER_H