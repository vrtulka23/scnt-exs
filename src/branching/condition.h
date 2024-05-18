#ifndef OPERATOR_CONDITION_H
#define OPERATOR_CONDITION_H

template <class A>
class OperatorCondition: public OperatorTernary<A> {
public:
  OperatorCondition(): OperatorTernary<A>("cond", "?", ":", CONDITION_OPERATOR) {}
  void operate_ternary(TokenListBase<A> *tokens) {
    Token<A> group2 = tokens->get_left();
    Token<A> group1 = tokens->get_left();
    Token<A> group3 = tokens->get_right();
    group1.atom->condition(group2.atom, group3.atom);
    tokens->put_left(group1);
  };
};

#endif // OPERATOR_CONDITION_H