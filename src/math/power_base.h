#ifndef OPERATOR_POWER_BASE_H
#define OPERATOR_POWER_BASE_H

namespace exs {
  
template <class A>
class OperatorPowerBase: public OperatorGroup<A, 2> {
public:
  OperatorPowerBase(): OperatorGroup<A, 2>("powb","powb(",POWER_BASE_OPERATOR) {}
  void operate_group(TokenListBase<A> *tokens) {
    Token<A> group2 = tokens->get_left();
    Token<A> group1 = tokens->get_left();
    group1.atom->math_power_base(group2.atom);
    tokens->put_left(group1);
  };
};

}

#endif // OPERATOR_POWER_BASE_H
