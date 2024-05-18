#ifndef OPERATOR_LOGARITHM_H
#define OPERATOR_LOGARITHM_H

template <class A>
class OperatorLogarithm: public OperatorArguments<A, 1> {
public:
  OperatorLogarithm(): OperatorArguments<A, 1>("log","log(",LOGARITHM_OPERATOR) {}
  void operate_arguments(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    left.atom->arg_logarithm();
    tokens->put_left(left);
  };
};

#endif // OPERATOR_LOGARITHM_H