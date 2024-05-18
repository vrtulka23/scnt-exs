#ifndef OPERATOR_TANGENS_H
#define OPERATOR_TANGENS_H

template <class A>
class OperatorTangens: public OperatorArguments<A, 1> {
public:
  OperatorTangens(): OperatorArguments<A, 1>("tan","tan(",TANGENS_OPERATOR) {}
  void operate_arguments(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    left.atom->arg_tangens();
    tokens->put_left(left);
  };
};

#endif // OPERATOR_TANGENS_H