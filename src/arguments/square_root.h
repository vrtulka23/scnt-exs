#ifndef OPERATOR_SQUARE_ROOT_H
#define OPERATOR_SQUARE_ROOT_H

template <class A>
class OperatorSquareRoot: public OperatorArguments<A, 1> {
public:
  OperatorSquareRoot(): OperatorArguments<A, 1>("sqrt","sqrt(",SQUARE_ROOT_OPERATOR) {}
  void operate_arguments(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    left.atom->arg_square_root();
    tokens->put_left(left);
  };
};

#endif // OPERATOR_SQUARE_ROOT_H