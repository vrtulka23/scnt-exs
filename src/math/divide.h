#ifndef EXS_OPERATOR_DIVIDE_H
#define EXS_OPERATOR_DIVIDE_H

namespace exs {
  
template <class A>
class OperatorDivide: public OperatorBase<A> {
public:
  OperatorDivide(std::string s="/"): OperatorBase<A>("div", s, DIVIDE_OPERATOR) {}
  void operate_binary(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    Token<A> right = tokens->get_right();
    left.atom->math_divide(right.atom);
    tokens->put_left(left);
  };
};

}
  
#endif // EXS_OPERATOR_DIVIDE_H
