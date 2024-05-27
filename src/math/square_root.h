#ifndef OPERATOR_SQUARE_ROOT_H
#define OPERATOR_SQUARE_ROOT_H

template <class A>
class OperatorSquareRoot: public OperatorGroup<A, 1> {
public:
  OperatorSquareRoot(): OperatorGroup<A, 1>("sqrt","sqrt(",SQUARE_ROOT_OPERATOR) {}
  void operate_group(TokenListBase<A> *tokens) {
    Token<A> group1 = tokens->get_left();
    group1.atom->math_square_root();
    tokens->put_left(group1);
  };
};

#endif // OPERATOR_SQUARE_ROOT_H
