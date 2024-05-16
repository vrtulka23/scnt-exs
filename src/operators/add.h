#ifndef OPERATOR_ADD_H
#define OPERATOR_ADD_H

template <class A>
class OperatorAdd: public OperatorBase<A> {
public:
  OperatorAdd(): OperatorBase<A>("add", "+", ADD_OPERATOR) {}
  void operate_unary(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    Token<A> right = tokens->get_right();
    if (left.type==EMPTY_TOKEN && right.type==ATOM_TOKEN) {
      tokens->put_left(right);
    } else if (right.optype==ADD_OPERATOR) {
      tokens->put_left(left);
      tokens->put_right(right);
    } else if (right.optype==SUBTRACT_OPERATOR) {
      tokens->put_left(left);
      tokens->put_right(right);
    } else if (left.type!=ATOM_TOKEN && right.type==ATOM_TOKEN) {
      tokens->put_left(left);
      tokens->put_right(right);      
    } else {
      tokens->put_left(left);
      tokens->put_left(Token<A>(OPERATOR_TOKEN, ADD_OPERATOR));
      tokens->put_right(right);            
    }
  };
  void operate_binary(TokenListBase<A> *tokens) {
    Token<A> left = tokens->get_left();
    Token<A> right = tokens->get_right();
    left.atom->add(right.atom);
    tokens->put_left(left);
  };
};

#endif // OPERATOR_ADD_H