#ifndef EXS_OPERATOR_NOT_EQUAL_H
#define EXS_OPERATOR_NOT_EQUAL_H

namespace exs {
  
template <class A>
class OperatorNotEqual: public OperatorBase<A> {
public:
    OperatorNotEqual(std::string s="!="): OperatorBase<A>("ne", s, NOT_EQUAL_OPERATOR) {}
    void operate_binary(TokenListBase<A> *tokens) {
        Token<A> left = tokens->get_left();
        Token<A> right = tokens->get_right();
        left.atom->comparison_not_equal(right.atom);
        tokens->put_left(left);
    };
};

}

#endif // EXS_OPERATOR_NOT_EQUAL_H
