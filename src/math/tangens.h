#ifndef OPERATOR_TANGENS_H
#define OPERATOR_TANGENS_H

template <class A>
class OperatorTangens: public OperatorGroup<A, 1> {
public:
  OperatorTangens(): OperatorGroup<A, 1>("tan","tan(",TANGENS_OPERATOR) {}
  void operate_group(TokenListBase<A> *tokens) {
    Token<A> group1 = tokens->get_left();
    group1.atom->math_tangens();
    tokens->put_left(group1);
  };
};

#endif // OPERATOR_TANGENS_H
