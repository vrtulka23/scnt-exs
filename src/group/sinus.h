#ifndef OPERATOR_SINUS_H
#define OPERATOR_SINUS_H

template <class A>
class OperatorSinus: public OperatorGroup<A, 1> {
public:
  OperatorSinus(): OperatorGroup<A, 1>("sin","sin(",SINUS_OPERATOR) {}
  void operate_group(TokenListBase<A> *tokens) {
    Token<A> arg1 = tokens->get_left();
    arg1.atom->arg_sinus();
    tokens->put_left(arg1);
  };
};

#endif // OPERATOR_SINUS_H