#ifndef OPERATOR_SINUS_H
#define OPERATOR_SINUS_H

template <class A>
class OperatorSinus: public OperatorArguments<A, 1> {
public:
  OperatorSinus(): OperatorArguments<A, 1>("sin","sin(",SINUS_OPERATOR) {}
  void operate_arguments(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    left.atom->arg_sinus();
    tokens->put_left(left);
  };
};

#endif // OPERATOR_SINUS_H