#ifndef OPERATOR_NOT_EQUAL_H
#define OPERATOR_NOT_EQUAL_H

template <class A>
class OperatorNotEqual: public OperatorBase<A> {
public:
  OperatorNotEqual(): OperatorBase<A>("ne", "!=", NOT_EQUAL_OPERATOR) {}
    void operate_binary(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    Token<A> right = tokens->get_right();
    left.atom->not_equal(right.atom);
    tokens->put_left(left);
  };
};

#endif // OPERATOR_NOT_EQUAL_H