#ifndef OPERATOR_GREATER_EQUAL_H
#define OPERATOR_GREATER_EQUAL_H

template <class A>
class OperatorGreaterEqual: public OperatorBase<A> {
public:
  OperatorGreaterEqual(std::string s=">="): OperatorBase<A>("ge", s, GREATER_EQUAL_OPERATOR) {}
    void operate_binary(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    Token<A> right = tokens->get_right();
    left.atom->comparison_greater_equal(right.atom);
    tokens->put_left(left);
  };
};

#endif // OPERATOR_GREATER_EQUAL_H