#include <unordered_map>

#include "main.h"

void SolverClass::solve(std::string expression) {
    Expression expr(expression);
    expr.print();
    TokenListClass tokens(&operators);
    
    // Tokenize expression
    while (expr.right.length()>0) {
        bool is_operator = false;
        for (auto o : operators.operators) {
            OperatorInterface *op = o.second;
            if (expr.right.rfind(op->symbol, 0) == 0) {
                is_operator = true;
                if (expr.left.length()>0) {
                    std::string left = expr.pop_left();
                    tokens.append(TokenClass(ATOM_TOKEN, left));
                }
                op->parse(expr);
                tokens.append(TokenClass(OPERATOR_TOKEN, op->type));
                expr.print();
            }
        }
        if (is_operator == false) {
            expr.shift();
            expr.print();
        }
    }
    if (expr.left.length()>0) {
        std::string left = expr.pop_left();
        tokens.append(TokenClass(ATOM_TOKEN, left));    
    }
    
    expr.print();
    tokens.print(true);   
    
    //std::unordered_map<OperationType, OperatorInterface*>;
}