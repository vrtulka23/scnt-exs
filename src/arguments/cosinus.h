#ifndef OPERATOR_COSINUS_H
#define OPERATOR_COSINUS_H

template <class A>
class OperatorCosinus: public OperatorArguments<A, 1> {
public:
  OperatorCosinus(): OperatorArguments<A, 1>("cos","cos(",COSINUS_OPERATOR) {}
  void operate_arguments(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    left.atom->arg_cosinus();
    tokens->put_left(left);
  };
};

#endif // OPERATOR_COSINUS_H