#include "../main.h"

void OperatorAdd::operate_unary(TokenListInterface *tokens) {
  TokenClass left = tokens->get_left();
  TokenClass right = tokens->get_right();
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
    tokens->put_left(TokenClass(OPERATOR_TOKEN, ADD_OPERATOR));
    tokens->put_right(right);            
  }
}

void OperatorAdd::operate_binary(TokenListInterface *tokens) {
  TokenClass left = tokens->get_left();
  TokenClass right = tokens->get_right();
  left.atom->value += right.atom->value;
  tokens->put_left(left);
}