#ifndef OPERATOR_NOT_H
#define OPERATOR_NOT_H

namespace exs {
  
template <class A>
class OperatorNot: public OperatorBase<A> {
public:
  OperatorNot(std::string s="!"): OperatorBase<A>("not", s, NOT_OPERATOR) {}
  void operate_unary(TokenListBase<A> *tokens) {
    Token<A> right = tokens->get_right();
    right.atom->logical_not();
    tokens->put_right(right);      
  };
};

}

#endif // OPERATOR_NOT_H
