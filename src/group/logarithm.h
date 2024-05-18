#ifndef OPERATOR_LOGARITHM_H
#define OPERATOR_LOGARITHM_H

template <class A>
class OperatorLogarithm: public OperatorGroup<A, 1> {
public:
  OperatorLogarithm(): OperatorGroup<A, 1>("log","log(",LOGARITHM_OPERATOR) {}
  void operate_group(TokenListBase<A> *tokens) {
    Token<A> arg1 = tokens->get_left();
    arg1.atom->arg_logarithm();
    tokens->put_left(arg1);
  };
};

#endif // OPERATOR_LOGARITHM_H