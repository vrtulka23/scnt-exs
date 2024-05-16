#ifndef OPERATOR_LOWER_H
#define OPERATOR_LOWER_H

template <class A>
class OperatorLower: public OperatorBase<A> {
public:
  OperatorLower(): OperatorBase<A>("lt", "<", LOWER_OPERATOR) {}
    void operate_binary(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    Token<A> right = tokens->get_right();
    left.atom->lower(right.atom);
    tokens->put_left(left);
  };
};

#endif // OPERATOR_LOWER_H