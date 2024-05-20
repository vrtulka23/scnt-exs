#ifndef OPERATOR_GREATER_H
#define OPERATOR_GREATER_H

template <class A>
class OperatorGreater: public OperatorBase<A> {
public:
    OperatorGreater(std::string s=">"): OperatorBase<A>("gt", s, GREATER_OPERATOR) {}
    void operate_binary(TokenListBase<A> *tokens) {
        Token<A> left = tokens->get_left();
        Token<A> right = tokens->get_right();
        left.atom->comparison_greater(right.atom);
        tokens->put_left(left);
    };
};

#endif // OPERATOR_GREATER_H