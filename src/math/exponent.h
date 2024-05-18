#ifndef OPERATOR_EXPONENT_H
#define OPERATOR_EXPONENT_H

template <class A>
class OperatorExponent: public OperatorGroup<A, 1> {
public:
  OperatorExponent(): OperatorGroup<A, 1>("exp","exp(",EXPONENT_OPERATOR) {}
  void operate_group(TokenListBase<A> *tokens) {
    Token<A> group1 = tokens->get_left();
    group1.atom->group_exponent();
    tokens->put_left(group1);
  };
};

#endif // OPERATOR_EXPONENT_H