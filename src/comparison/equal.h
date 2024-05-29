#ifndef EXS_OPERATOR_EQUAL_H
#define EXS_OPERATOR_EQUAL_H

namespace exs {
  
template <class A>
class OperatorEqual: public OperatorBase<A> {
public:
    OperatorEqual(std::string s="=="): OperatorBase<A>("eq", s, EQUAL_OPERATOR) {}
    void operate_binary(TokenListBase<A> *tokens) {
        Token<A> left = tokens->get_left();
        Token<A> right = tokens->get_right();
        left.atom->comparison_equal(right.atom);
        tokens->put_left(left);
    };
};

}

#endif // EXS_OPERATOR_EQUAL_H
