#import "main.h"

void TokenList::append(TokenType t) {
  right.push_back(Token(t));
}
void TokenList::append(TokenType t, OperatorType o) {
  right.push_back(Token(t, o));
}
void TokenList::append(TokenType t, AtomBase *a) {
  right.push_back(Token(t, a));
}

Token TokenList::get_left() {
  if (left.empty()) {
    return Token(EMPTY_TOKEN);
  } else {
    Token t = left.back();
    left.pop_back();
    return t;
  }
}

Token TokenList::get_right() {
  if (right.empty()) {
    return Token(EMPTY_TOKEN);
  } else {
      Token t = right.front();
      right.pop_front();
      return t;
  }
}

void TokenList::put_left(Token t) {
  if (t.type!=EMPTY_TOKEN) {
    left.push_back(t);
  }
}

void TokenList::put_right(Token t) {
  if (t.type!=EMPTY_TOKEN) {
    right.push_front(t);
  }
}

void TokenList::operate(const std::vector<OperatorType> &ops, OperationType oitype) {
  // perform operations on the individual tokens
  while (!right.empty()) {
    Token token = get_right();
    if (std::find(ops.begin(), ops.end(), token.optype) != ops.end()) {
      OperatorBase *op = operators->select(token.optype);
      // token is an operator
      if (oitype==UNARY_OPERATION) {
      	op->operate_unary(this);
      } else if (oitype==BINARY_OPERATION) {
	      op->operate_binary(this);
      } else if (oitype==ARGUMENTS_OPERATION) {
	      op->operate_arguments(this);
      } else {
	      throw std::invalid_argument("Invalid operation type");
      }
    } else {
      // token is something else
      put_left(token);
    }
  }
  // move all tokens from left to right
  left.swap(right);
}

void TokenList::print(bool details) {
  if (details) {
    std::cout << "TokenList( ";
    for (auto i = left.begin(); i!= left.end(); ++i) {
      print_details(i);
    }
    std::cout << "| ";
    for (auto i = right.begin(); i!= right.end(); ++i) {
      print_details(i);
    }
    std::cout << ")" << std::endl;
    } else {
    std::cout << "TokenList(" << left.size() << " | " << right.size() << ")" << std::endl;
  }
}

void TokenList::print_details(std::deque<Token>::iterator i) {
  switch (i->type) {
  case EMPTY_TOKEN: std::cout << "E "; break;
  case ATOM_TOKEN: std::cout << "A "; break;
  case OPERATOR_TOKEN:
    OperatorBase *op = operators->select(i->optype);
    std::cout << op->name << " ";
    break;
  }
}
