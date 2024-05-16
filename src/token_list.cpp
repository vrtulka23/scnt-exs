#import "main.h"

void TokenListClass::append(TokenType t) {
  right.push_back(TokenClass(t));
}
void TokenListClass::append(TokenType t, OperatorType o) {
  right.push_back(TokenClass(t, o));
}
void TokenListClass::append(TokenType t, AtomBase *a) {
  right.push_back(TokenClass(t, a));
}

TokenClass TokenListClass::get_left() {
  if (left.empty()) {
    return TokenClass(EMPTY_TOKEN);
  } else {
    TokenClass t = left.back();
    left.pop_back();
    return t;
  }
}

TokenClass TokenListClass::get_right() {
  if (right.empty()) {
    return TokenClass(EMPTY_TOKEN);
  } else {
      TokenClass t = right.front();
      right.pop_front();
      return t;
  }
}

void TokenListClass::put_left(TokenClass t) {
  if (t.type!=EMPTY_TOKEN) {
    left.push_back(t);
  }
}

void TokenListClass::put_right(TokenClass t) {
  if (t.type!=EMPTY_TOKEN) {
    right.push_front(t);
  }
}

void TokenListClass::operate(const std::vector<OperatorType> &ops, OperationType oitype) {
  // perform operations on the individual tokens
  while (!right.empty()) {
    TokenClass token = get_right();
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

void TokenListClass::print(bool details) {
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

void TokenListClass::print_details(std::deque<TokenClass>::iterator i) {
  switch (i->type) {
  case EMPTY_TOKEN: std::cout << "E "; break;
  case ATOM_TOKEN: std::cout << "A "; break;
  case OPERATOR_TOKEN:
    OperatorBase *op = operators->select(i->optype);
    std::cout << op->name << " ";
    break;
  }
}
