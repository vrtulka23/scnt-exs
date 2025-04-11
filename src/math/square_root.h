#ifndef EXS_OPERATOR_SQUARE_ROOT_H
#define EXS_OPERATOR_SQUARE_ROOT_H

namespace exs {
  
template <class A, typename S = EmptySettings>
class OperatorSquareRoot: public OperatorGroup<A, 1, S> {
public:
  OperatorSquareRoot(): OperatorGroup<A, 1, S>("sqrt","sqrt(",SQUARE_ROOT_OPERATOR) {}
  void operate_group(TokenListBase<A>* tokens) override {
    Token<A> group1 = tokens->get_left();
    group1.atom->math_square_root();
    tokens->put_left(group1);
  };
};

}

#endif // EXS_OPERATOR_SQUARE_ROOT_H
