#ifndef EXS_OPERATOR_TANGENS_H
#define EXS_OPERATOR_TANGENS_H

namespace exs {
  
template <class A, typename S = EmptySettings>
class OperatorTangens: public OperatorGroup<A, 1, S> {
public:
  OperatorTangens(): OperatorGroup<A, 1, S>("tan","tan(",TANGENS_OPERATOR) {}
  void operate_group(TokenListBase<A>* tokens) override {
    Token<A> group1 = tokens->get_left();
    group1.atom->math_tangens();
    tokens->put_left(group1);
  };
};

}
  
#endif // EXS_OPERATOR_TANGENS_H
