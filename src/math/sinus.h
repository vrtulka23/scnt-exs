#ifndef OPERATOR_SINUS_H
#define OPERATOR_SINUS_H

template <class A>
class OperatorSinus: public OperatorGroup<A, 1> {
public:
  OperatorSinus(): OperatorGroup<A, 1>("sin","sin(",SINUS_OPERATOR) {}
  void operate_group(TokenListBase<A> *tokens) {
    Token<A> group1 = tokens->get_left();
    group1.atom->math_sinus();
    tokens->put_left(group1);
  };
};

#endif // OPERATOR_SINUS_H
