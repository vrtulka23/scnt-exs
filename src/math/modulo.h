#ifndef EXS_OPERATOR_MODULO_H
#define EXS_OPERATOR_MODULO_H

namespace exs {
  
template <class A>
class OperatorModulo: public OperatorBase<A> {
public:
  OperatorModulo(std::string s="%"): OperatorBase<A>("mod", s, MODULO_OPERATOR) {}
  void operate_binary(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    Token<A> right = tokens->get_right();
    left.atom->math_modulo(right.atom);
    tokens->put_left(left);
  };
};

}

#endif // EXS_OPERATOR_MODULO_H
