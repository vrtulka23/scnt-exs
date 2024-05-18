#ifndef OPERATOR_CONDITION_H
#define OPERATOR_CONDITION_H

template <class A>
class OperatorCondition: public OperatorTernary<A> {
public:
  OperatorCondition(): OperatorTernary<A>("cond", "?", ":", CONDITION_OPERATOR) {}
  void operate_ternary(TokenListBase<A> *tokens) {
    Token<A> arg2 = tokens->get_left();
    Token<A> arg1 = tokens->get_left();
    Token<A> arg3 = tokens->get_right();
    arg1.atom->condition(arg2.atom, arg3.atom);
    tokens->put_left(arg1);
  };
};

#endif // OPERATOR_CONDITION_H