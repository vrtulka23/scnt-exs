#ifndef EXS_OPERATOR_LOWER_H
#define EXS_OPERATOR_LOWER_H

namespace exs {
  
template <class A>
class OperatorLower: public OperatorBase<A> {
public:
    OperatorLower(std::string s="<"): OperatorBase<A>("lt", s, LOWER_OPERATOR) {}
    void operate_binary(TokenListBase<A> *tokens) {
        Token<A> left = tokens->get_left();
        Token<A> right = tokens->get_right();
        left.atom->comparison_lower(right.atom);
        tokens->put_left(left);
    };
};

}

#endif // EXS_OPERATOR_LOWER_H
