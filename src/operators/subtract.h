#ifndef OPERATOR_SUBTRACT_H
#define OPERATOR_SUBTRACT_H

class OperatorSubtract: public OperatorBase {
public:
  OperatorSubtract(): OperatorBase("sub", "-", SUBTRACT_OPERATOR) {}
  void operate_unary(TokenListBase *tokens) {
    Token left = tokens->get_left();
    Token right = tokens->get_right();
    if (left.type==EMPTY_TOKEN && right.type==ATOM_TOKEN) {
      right.atom->value = -std::get<float>(right.atom->value);
      tokens->put_right(right);  
    } else if (right.optype==ADD_OPERATOR) {
      tokens->put_left(left);
      tokens->put_right(Token(OPERATOR_TOKEN, SUBTRACT_OPERATOR));
    } else if (right.optype==SUBTRACT_OPERATOR) {
      tokens->put_left(left);
      tokens->put_right(Token(OPERATOR_TOKEN, ADD_OPERATOR));
    } else if (left.type!=ATOM_TOKEN && right.type==ATOM_TOKEN) {
      tokens->put_left(left);
      right.atom->value = -std::get<float>(right.atom->value);
      tokens->put_right(right);      
    } else {
      tokens->put_left(left);
      tokens->put_left(Token(OPERATOR_TOKEN, SUBTRACT_OPERATOR));
      tokens->put_right(right);            
    }
  };
  void operate_binary(TokenListBase *tokens) {
    Token left = tokens->get_left();
    Token right = tokens->get_right();
    left.atom->value = std::get<float>(left.atom->value) - std::get<float>(right.atom->value);
    tokens->put_left(left);
  };
};

#endif // OPERATOR_SUBTRACT_H