#ifndef SOLVER_H
#define SOLVER_H

#include <memory>
#include <unordered_map>
#include <stdexcept>

template <class A>
class Solver {
public:
    OperatorList<A> operators;
    StepList steps;
    Solver() {init_steps();init_operators();};
    Solver(OperatorList<A> &o): operators(o) {init_steps();};
    Solver(StepList &s): steps(s) {init_operators();};
    Solver(OperatorList<A> &o, StepList &s): operators(o), steps(s) {};
    A solve(std::string expression) {
        Expression expr(expression);
        //expr.print();
        TokenList<A> tokens(&operators);
        AtomList<A> atoms;
        
        // Tokenize expression
        while (expr.right.length()>0) {
            bool is_operator = false;
            for (auto o : operators.operators) {
                OperatorBase<A> *op = &(*o.second);
                if (expr.right.rfind(op->symbol, 0) == 0) {
                    is_operator = true;
                    std::string left = expr.pop_left();
                    if (left.length()>0) {
                        A *a = atoms.append(left);
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
            A *a = atoms.append(left);
            tokens.append(ATOM_TOKEN, a);
        }
        //expr.print();  
        
        for (auto s: steps.steps) {
            //tokens.print(true); 
            tokens.operate(s.second, s.first);
        }
        //tokens.print(true);   
        
        if (tokens.left.size()>0 or tokens.right.size()>1) {
            tokens.print(true);
            throw std::logic_error("Cannot solve expression due to unprocessed tokens");
        }
        
        Token token = tokens.get_right();
        //std::cout << &token << " " << token.atom << " " << token.atom->value << std::endl;
        return *token.atom;
    };
private:
    void init_steps() {
        steps.append(UNARY_OPERATION,  {ADD_OPERATOR, SUBTRACT_OPERATOR});
        steps.append(BINARY_OPERATION, {POWER_OPERATOR});
        steps.append(BINARY_OPERATION, {MULTIPLY_OPERATOR, DIVIDE_OPERATOR});
        steps.append(BINARY_OPERATION, {ADD_OPERATOR, SUBTRACT_OPERATOR});
    }
    void init_operators() {
        operators.append(ADD_OPERATOR,      std::make_shared<OperatorAdd<A>>());
        operators.append(SUBTRACT_OPERATOR, std::make_shared<OperatorSubtract<A>>());
        operators.append(MULTIPLY_OPERATOR, std::make_shared<OperatorMultiply<A>>());
        operators.append(DIVIDE_OPERATOR,   std::make_shared<OperatorDivide<A>>());
        operators.append(POWER_OPERATOR,    std::make_shared<OperatorPower<A>>());
    }
};

#endif // SOLVER_H