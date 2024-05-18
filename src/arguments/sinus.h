#ifndef OPERATOR_SINUS_H
#define OPERATOR_SINUS_H

template <class A>
class OperatorSinus: public OperatorArguments<A, 1> {
public:
  OperatorSinus(): OperatorArguments<A, 1>("sin","sin(",SINUS_OPERATOR) {}
  void operate_arguments(TokenListBase<A> *tokens) {
    Token<A> arg1 = tokens->get_left();
    arg1.atom->arg_sinus();
    tokens->put_left(arg1);
  };
};

#endif // OPERATOR_SINUS_H