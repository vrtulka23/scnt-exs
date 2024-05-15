#include "../main.h"

void OperatorSubtract::operate_unary(TokenListInterface *tokens) {
  TokenClass left = tokens->get_left();
  TokenClass right = tokens->get_right();
  if (left.type==EMPTY_TOKEN && right.type==ATOM_TOKEN) {
    tokens->put_left(-right);
  } else if (right.optype==ADD_OPERATOR) {
    tokens->put_left(left);
    tokens->put_right(TokenClass(OPERATOR_TOKEN, SUBTRACT_OPERATOR));
  } else if (right.optype==SUBTRACT_OPERATOR) {
    tokens->put_left(left);
    tokens->put_right(TokenClass(OPERATOR_TOKEN, ADD_OPERATOR));
  } else if (left.type==ATOM_TOKEN && right.type==ATOM_TOKEN) {
    tokens->put_left(left);
    tokens->put_right(-right);      
  } else {
    tokens->put_left(left);
    tokens->put_left(TokenClass(OPERATOR_TOKEN, SUBTRACT_OPERATOR));
    tokens->put_right(right);            
  }
}

void OperatorSubtract::operate_binary(TokenListInterface *tokens) {
  TokenClass left = tokens->get_left();
  TokenClass right = tokens->get_right();
  tokens->put_left(left - right);
}