#ifndef OPERATOR_POWER_BASE_H
#define OPERATOR_POWER_BASE_H

template <class A>
class OperatorPowerBase: public OperatorGroup<A, 2> {
public:
  OperatorPowerBase(): OperatorGroup<A, 2>("powb","powb(",POWER_BASE_OPERATOR) {}
  void operate_group(TokenListBase<A> *tokens) {
    Token<A> arg2 = tokens->get_left();
    Token<A> arg1 = tokens->get_left();
    arg1.atom->arg_power_base(arg2.atom);
    tokens->put_left(arg1);
  };
};

#endif // OPERATOR_POWER_BASE_H