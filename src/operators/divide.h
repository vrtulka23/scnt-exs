#ifndef OPERATOR_DIVIDE_H
#define OPERATOR_DIVIDE_H

template <class A>
class OperatorDivide: public OperatorBase<A> {
public:
  OperatorDivide(): OperatorBase<A>("div", "/", DIVIDE_OPERATOR) {}
  void operate_binary(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    Token<A> right = tokens->get_right();
    left.atom->value = std::get<float>(left.atom->value) / std::get<float>(right.atom->value);
    tokens->put_left(left);
  };
};

#endif // OPERATOR_DIVIDE_H