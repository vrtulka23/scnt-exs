#ifndef TOKEN_LIST_H
#define TOKEN_LIST_H

#include <deque>
#include <algorithm>
#include <vector>
#include <stdexcept>

namespace exs {
  
template <class A>
class TokenList: public TokenListBase<A> {
public:
  std::deque<Token<A>> left;
  std::deque<Token<A>> right;
  OperatorList<A> *operators;
  AtomList<A> atoms;
  TokenList(OperatorList<A> *o): operators(o) {};
  void append(TokenType t) {
    right.push_back(Token<A>(t));
  };
  void append(TokenType t, OperatorType o) {
    right.push_back(Token<A>(t, o));
  };
  void append(TokenType t, std::string s) {
    A *a = atoms.append(s);
    right.push_back(Token<A>(t, a));
  };
  void append(TokenType t, A at) {
    A *a = atoms.append(at);
    right.push_back(Token<A>(t, a));
  };
  Token<A> get_left() {
    if (left.empty()) {
      return Token<A>(EMPTY_TOKEN);
    } else {
      Token<A> t = left.back();
      left.pop_back();
      return t;
    }
  };
  Token<A> get_right() {
    if (right.empty()) {
      return Token<A>(EMPTY_TOKEN);
    } else {
        Token<A> t = right.front();
        right.pop_front();
        return t;
    }
  };
  void put_left(Token<A> t) {
    if (t.type!=EMPTY_TOKEN) {
      left.push_back(t);
    }
  };
  void put_right(Token<A> t) {
    if (t.type!=EMPTY_TOKEN) {
      right.push_front(t);
    }
  };
  void operate(const std::vector<OperatorType> &ops, OperationType oitype) {
    /*
    std::cout << "token_list::operate oitype=" << oitype << " operators=[ ";
    for (auto i: ops) std::cout << i << " ";
    std::cout << "]" << std::endl;
    print(true);
    */
    // perform operations on the individual tokens
    while (!right.empty()) {
      Token<A> token = get_right();
      //token.print();
      if (std::find(ops.begin(), ops.end(), token.optype) != ops.end()) {
        OperatorBase<A> *op = operators->select(token.optype);
        // token is an operator
        if (oitype==UNARY_OPERATION) {
	  op->operate_unary(this);
        } else if (oitype==BINARY_OPERATION) {
	  op->operate_binary(this);
        } else if (oitype==TERNARY_OPERATION) {
	  op->operate_ternary(this);
        } else if (oitype==GROUP_OPERATION) {
	  op->operate_group(this);
        } else {
	  throw std::invalid_argument("Invalid operation type: "+std::to_string(oitype));
        }
      } else {
        // token is something else
	//std::cout << "putting left" << std::endl;
        put_left(token);
      }
      //print(true);
    }
    // move all tokens from left to right
    left.swap(right);
    //print(true);
    //std::cout << std::endl;
  };
  void print(bool details=false) {
    if (details) {
      std::cout << "TokenList( ";
      for (auto i = left.begin(); i!= left.end(); ++i) {
        print_details(i->type, i->optype, i->atom);
      }
      std::cout << "| ";
      for (auto i = right.begin(); i!= right.end(); ++i) {
        print_details(i->type, i->optype, i->atom);
      }
      std::cout << ")" << std::endl;
      } else {
      std::cout << "TokenList(" << left.size() << " | " << right.size() << ")" << std::endl;
    }
  };
private:
  void print_details(TokenType type, OperatorType optype, A *atom) {
    switch (type) {
    case EMPTY_TOKEN: std::cout << "E "; break;
    case ATOM_TOKEN:
      std::cout << "A{" << atom->to_string() << "} ";
      break;
    case OPERATOR_TOKEN:
      OperatorBase<A> *op = operators->select(optype);
      std::cout << op->name << " ";
      break;
    }
  };
};

}
  
#endif // TOKEN_LIST_H
