#ifndef TOKEN_LIST_H
#define TOKEN_LIST_H

#include <deque>
#include <algorithm>
#include <vector>
#include <stdexcept>

template <class A>
class TokenList: public TokenListBase {
public:
  std::deque<Token> left;
  std::deque<Token> right;
  OperatorList *operators;
  TokenList(OperatorList *o): operators(o) {};
  void append(TokenType t) {
    right.push_back(Token(t));
  };
  void append(TokenType t, OperatorType o) {
    right.push_back(Token(t, o));
  };
  void append(TokenType t, A *a) {
    right.push_back(Token(t, a));
  };
  Token get_left() {
    if (left.empty()) {
      return Token(EMPTY_TOKEN);
    } else {
      Token t = left.back();
      left.pop_back();
      return t;
    }
  };
  Token get_right() {
    if (right.empty()) {
      return Token(EMPTY_TOKEN);
    } else {
        Token t = right.front();
        right.pop_front();
        return t;
    }
  };
  void put_left(Token t) {
    if (t.type!=EMPTY_TOKEN) {
      left.push_back(t);
    }
  };
  void put_right(Token t) {
    if (t.type!=EMPTY_TOKEN) {
      right.push_front(t);
    }
  };
  void operate(const std::vector<OperatorType> &ops, OperationType oitype) {
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
  };
  void print(bool details=false) {
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
  };
private:
  void print_details(std::deque<Token>::iterator i) {
    switch (i->type) {
    case EMPTY_TOKEN: std::cout << "E "; break;
    case ATOM_TOKEN: std::cout << "A "; break;
    case OPERATOR_TOKEN:
      OperatorBase *op = operators->select(i->optype);
      std::cout << op->name << " ";
      break;
    }
  };
};
  
#endif // TOKEN_LIST_H
