#ifndef OPERATOR_MULTIPLY_H
#define OPERATOR_MULTIPLY_H

template <class A>
class OperatorMultiply: public OperatorBase<A> {
public:
  OperatorMultiply(): OperatorBase<A>("mul", "*", MULTIPLY_OPERATOR) {}
  void operate_binary(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    Token<A> right = tokens->get_right();
    left.atom->value = std::get<float>(left.atom->value) * std::get<float>(right.atom->value);
    tokens->put_left(left);
  };
};

#endif // OPERATOR_MULTIPLY_H