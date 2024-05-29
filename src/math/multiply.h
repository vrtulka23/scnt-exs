#ifndef EXS_OPERATOR_MULTIPLY_H
#define EXS_OPERATOR_MULTIPLY_H

namespace exs {

template <class A>
class OperatorMultiply: public OperatorBase<A> {
public:
  OperatorMultiply(std::string s="*"): OperatorBase<A>("mul", s, MULTIPLY_OPERATOR) {}
  void operate_binary(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    Token<A> right = tokens->get_right();
    left.atom->math_multiply(right.atom);
    tokens->put_left(left);
  };
};

}
  
#endif // EXS_OPERATOR_MULTIPLY_H
