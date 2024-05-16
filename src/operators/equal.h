#ifndef OPERATOR_EQUAL_H
#define OPERATOR_EQUAL_H

template <class A>
class OperatorEqual: public OperatorBase<A> {
public:
  OperatorEqual(): OperatorBase<A>("eq", "==", EQUAL_OPERATOR) {}
    void operate_binary(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    Token<A> right = tokens->get_right();
    left.atom->equal(right.atom);
    tokens->put_left(left);
  };
};

#endif // OPERATOR_EQUAL_H