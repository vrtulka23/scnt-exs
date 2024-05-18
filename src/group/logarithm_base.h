#ifndef OPERATOR_LOGARITHM_BASE_H
#define OPERATOR_LOGARITHM_BASE_H

template <class A>
class OperatorLogarithmBase: public OperatorGroup<A, 2> {
public:
  OperatorLogarithmBase(): OperatorGroup<A, 2>("logb","logb(",LOGARITHM_BASE_OPERATOR) {}
  void operate_group(TokenListBase<A> *tokens) {
    Token<A> arg2 = tokens->get_left();
    Token<A> arg1 = tokens->get_left();
    arg1.atom->arg_logarithm_base(arg2.atom);
    tokens->put_left(arg1);
  };
};

#endif // OPERATOR_LOGARITHM_BASE_H