#ifndef OPERATOR_DIVIDE_H
#define OPERATOR_DIVIDE_H

class OperatorDivide: public OperatorBase {
public:
  OperatorDivide(): OperatorBase("div", "/", DIVIDE_OPERATOR) {}
  void operate_binary(TokenListBase *tokens) {
    Token left = tokens->get_left();
    Token right = tokens->get_right();
    left.atom->value = std::get<float>(left.atom->value) / std::get<float>(right.atom->value);
    tokens->put_left(left);
  };
};

#endif // OPERATOR_DIVIDE_H