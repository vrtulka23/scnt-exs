#ifndef OPERATOR_TANGENS_H
#define OPERATOR_TANGENS_H

template <class A>
class OperatorTangens: public OperatorArguments<A, 1> {
public:
  OperatorTangens(): OperatorArguments<A, 1>("tan","tan(",TANGENS_OPERATOR) {}
  void operate_arguments(TokenListBase<A> *tokens) {
    Token<A> arg1 = tokens->get_left();
    arg1.atom->arg_tangens();
    tokens->put_left(arg1);
  };
};

#endif // OPERATOR_TANGENS_H