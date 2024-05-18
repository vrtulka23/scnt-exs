#ifndef OPERATOR_LOGARITHM_10_H
#define OPERATOR_LOGARITHM_10_H

template <class A>
class OperatorLogarithm10: public OperatorArguments<A, 1> {
public:
  OperatorLogarithm10(): OperatorArguments<A, 1>("log10","log10(",LOGARITHM_10_OPERATOR) {}
  void operate_arguments(TokenListBase<A> *tokens) {
    Token<A> arg1 = tokens->get_left();
    arg1.atom->arg_logarithm_10();
    tokens->put_left(arg1);
  };
};

#endif // OPERATOR_LOGARITHM_10_H