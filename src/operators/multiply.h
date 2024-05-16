#ifndef OPERATOR_MULTIPLY_H
#define OPERATOR_MULTIPLY_H


class OperatorMultiply: public OperatorBase {
public:
  OperatorMultiply(): OperatorBase("mul", "*", MULTIPLY_OPERATOR) {}
  void operate_binary(TokenListBase *tokens) {
    Token left = tokens->get_left();
    Token right = tokens->get_right();
    left.atom->value = std::get<float>(left.atom->value) * std::get<float>(right.atom->value);
    tokens->put_left(left);
  };
};

#endif // OPERATOR_MULTIPLY_H