#ifndef EXS_OPERATOR_EXPONENT_H
#define EXS_OPERATOR_EXPONENT_H

namespace exs {
  
template <class A, typename S = EmptySettings>
class OperatorExponent: public OperatorGroup<A, 1, S> {
public:
  OperatorExponent(): OperatorGroup<A, 1, S>("exp","exp(",EXPONENT_OPERATOR) {}
  void operate_group(TokenListBase<A>* tokens) override {
    Token<A> group1 = tokens->get_left();
    group1.atom->math_exponent();
    tokens->put_left(group1);
  };
};

}

#endif // EXS_OPERATOR_EXPONENT_H
