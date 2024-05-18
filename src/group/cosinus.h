#ifndef OPERATOR_COSINUS_H
#define OPERATOR_COSINUS_H

template <class A>
class OperatorCosinus: public OperatorGroup<A, 1> {
public:
  OperatorCosinus(): OperatorGroup<A, 1>("cos","cos(",COSINUS_OPERATOR) {}
  void operate_group(TokenListBase<A> *tokens) {
    Token<A> arg1 = tokens->get_left();
    arg1.atom->arg_cosinus();
    tokens->put_left(arg1);
  };
};

#endif // OPERATOR_COSINUS_H