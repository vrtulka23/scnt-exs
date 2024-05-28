#ifndef OPERATOR_LOGARITHM_10_H
#define OPERATOR_LOGARITHM_10_H

namespace exs {
  
template <class A>
class OperatorLogarithm10: public OperatorGroup<A, 1> {
public:
  OperatorLogarithm10(): OperatorGroup<A, 1>("log10","log10(",LOGARITHM_10_OPERATOR) {}
  void operate_group(TokenListBase<A> *tokens) {
    Token<A> group1 = tokens->get_left();
    group1.atom->math_logarithm_10();
    tokens->put_left(group1);
  };
};

}

#endif // OPERATOR_LOGARITHM_10_H
