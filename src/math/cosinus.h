#ifndef EXS_OPERATOR_COSINUS_H
#define EXS_OPERATOR_COSINUS_H

namespace exs {
  
template <class A>
class OperatorCosinus: public OperatorGroup<A, 1> {
public:
  OperatorCosinus(): OperatorGroup<A, 1>("cos","cos(",COSINUS_OPERATOR) {}
  void operate_group(TokenListBase<A> *tokens) {
    Token<A> group1 = tokens->get_left();
    group1.atom->math_cosinus();
    tokens->put_left(group1);
  };
};

}

#endif // EXS_OPERATOR_COSINUS_H
