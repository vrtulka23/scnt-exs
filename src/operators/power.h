#ifndef OPERATOR_POWER_H
#define OPERATOR_POWER_H

#include <math.h>

template <class A>
class OperatorPower: public OperatorBase<A> {
public:
  OperatorPower(): OperatorBase<A>("pow", "**", POWER_OPERATOR) {}
  void operate_binary(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    Token<A> right = tokens->get_right();
    left.atom->value = pow(std::get<float>(left.atom->value), std::get<float>(right.atom->value));
    tokens->put_left(left);
  };
};

#endif // OPERATOR_POWER_H