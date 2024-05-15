#include <unordered_map>
#include <stdexcept>

#include "main.h"

AtomInterface SolverClass::solve(std::string expression) {
    Expression expr(expression);
    //expr.print();
    TokenListClass tokens(&operators);
    AtomListClass atoms;
    
    // Tokenize expression
    while (expr.right.length()>0) {
        bool is_operator = false;
        for (auto o : operators.operators) {
            OperatorInterface *op = o.second;
            if (expr.right.rfind(op->symbol, 0) == 0) {
                is_operator = true;
                std::string left = expr.pop_left();
                if (left.length()>0) {
                    AtomInterface *a = atoms.append(left);
                    tokens.append(ATOM_TOKEN, a);
                }
                op->parse(expr);
                tokens.append(OPERATOR_TOKEN, op->type);
                //expr.print();
            }
        }
        if (is_operator == false) {
            expr.shift();
            //expr.print();
        }
    }
    std::string left = expr.pop_left();
    if (left.length()>0) {
        AtomInterface *a = atoms.append(left);
        tokens.append(ATOM_TOKEN, a);
    }
    //expr.print();  
    
    for (auto s: steps) {
        //tokens.print(true); 
        tokens.operate(s.second, s.first);
    }
    //tokens.print(true);   
    
    if (tokens.left.size()>0 or tokens.right.size()>1) {
        tokens.print(true);
        throw std::logic_error("Cannot solve expression due to unprocessed tokens");
    }
    
    TokenClass token = tokens.get_right();
    //std::cout << &token << " " << token.atom << " " << token.atom->value << std::endl;
    return *token.atom;
}