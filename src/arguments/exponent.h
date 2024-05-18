#ifndef OPERATOR_EXPONENT_H
#define OPERATOR_EXPONENT_H

template <class A>
class OperatorExponent: public OperatorArguments<A, 1> {
public:
  OperatorExponent(): OperatorArguments<A, 1>("exp","exp(",EXPONENT_OPERATOR) {}
  void operate_arguments(TokenListBase<A> *tokens) {
    Token<A> arg1 = tokens->get_left();
    arg1.atom->arg_exponent();
    tokens->put_left(arg1);
  };
};

#endif // OPERATOR_EXPONENT_H