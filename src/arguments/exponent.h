#ifndef OPERATOR_EXPONENT_H
#define OPERATOR_EXPONENT_H

template <class A>
class OperatorExponent: public OperatorArguments<A, 1> {
public:
  OperatorExponent(): OperatorArguments<A, 1>("par","exp(",EXPONENT_OPERATOR) {}
  void operate_arguments(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    left.atom->arg_exponent();
    tokens->put_left(left);
  };
};

#endif // OPERATOR_EXPONENT_H