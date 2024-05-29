#ifndef EXS_SOLVER_H
#define EXS_SOLVER_H

#include <memory>
#include <unordered_map>
#include <stdexcept>

namespace exs {

template <class A>
class Solver {
public:
    OperatorList<A> operators;
    StepList steps;
    Solver() {
        init_steps();
        init_operators();
    };
    Solver(OperatorList<A> &o): operators(o) {
        init_steps();
    };
    Solver(StepList &s): steps(s) {
        init_operators();
    };
    Solver(OperatorList<A> &o, StepList &s): operators(o), steps(s) {};
    A solve(std::string expression) {
        Expression expr(expression);
        //expr.print();
        TokenList<A> tokens(&operators);
        
        // Tokenize expression
        while (expr.right.length()>0) {
            bool is_operator = false;
            for (auto o : operators.order) {
                OperatorBase<A> *op = operators.select(o);
                //std::cout << op->symbol << std::endl;
                if (expr.right.rfind(op->symbol, 0) == 0) {
                    is_operator = true;
                    std::string left = expr.pop_left();
                    if (left.length()>0) {
                        tokens.append(ATOM_TOKEN, left);
                    }
                    op->parse(expr);
                    if (op->groups.size()>0) {
                        std::vector<std::string> groups = op->groups;
                        //std::cout <<  groups.size() << std::endl;
                        for (auto e: groups) {
                            tokens.append(ATOM_TOKEN, solve(e));
                        }
                    }
                    tokens.append(OPERATOR_TOKEN, op->type);
                    //expr.print();
                }
            }
            if (is_operator == false) {
                expr.shift();
                //expr.print();
            }
            //tokens.print(true);
        }
        std::string left = expr.pop_left();
        if (left.length()>0) {
            tokens.append(ATOM_TOKEN, left);
        }
        //expr.print();  
        
        for (auto s: steps.steps) {
	  //tokens.print(true); 
          tokens.operate(s.second, s.first);
        }
        //tokens.print(true);
        
        if (tokens.left.size()>0 or tokens.right.size()>1) {
            //tokens.print(true);
	  throw std::logic_error("Cannot solve expression due to unprocessed tokens: "+tokens.to_string(true));
        }
        
        Token token = tokens.get_right();
        //std::cout << &token << " " << token.atom << " " << token.atom->value << std::endl;
        return *token.atom;
    };
private:
    void init_steps() {
        steps.append(GROUP_OPERATION, {
            PARENTHESES_OPERATOR, EXPONENT_OPERATOR, LOGARITHM_OPERATOR,
            LOGARITHM_10_OPERATOR, LOGARITHM_BASE_OPERATOR, POWER_BASE_OPERATOR,
            SQUARE_ROOT_OPERATOR, SINUS_OPERATOR, COSINUS_OPERATOR, TANGENS_OPERATOR
        });
        steps.append(UNARY_OPERATION,     {ADD_OPERATOR, SUBTRACT_OPERATOR});
        steps.append(TERNARY_OPERATION,   {CONDITION_OPERATOR});
        steps.append(BINARY_OPERATION,    {POWER_OPERATOR});
        steps.append(BINARY_OPERATION,    {MULTIPLY_OPERATOR, DIVIDE_OPERATOR, MODULO_OPERATOR});
        steps.append(BINARY_OPERATION,    {ADD_OPERATOR, SUBTRACT_OPERATOR});
        steps.append(BINARY_OPERATION,    {
            LOWER_EQUAL_OPERATOR,GREATER_EQUAL_OPERATOR,
            LOWER_OPERATOR,GREATER_OPERATOR
        });
        steps.append(BINARY_OPERATION,    {EQUAL_OPERATOR,NOT_EQUAL_OPERATOR});
        steps.append(UNARY_OPERATION,     {NOT_OPERATOR});
        steps.append(BINARY_OPERATION,    {AND_OPERATOR});
        steps.append(BINARY_OPERATION,    {OR_OPERATOR});
    }
    void init_operators() {
        operators.append(TANGENS_OPERATOR,        std::make_shared<OperatorTangens<A>>());
        operators.append(COSINUS_OPERATOR,        std::make_shared<OperatorCosinus<A>>());
        operators.append(SINUS_OPERATOR,          std::make_shared<OperatorSinus<A>>());
        operators.append(SQUARE_ROOT_OPERATOR,    std::make_shared<OperatorSquareRoot<A>>());
        operators.append(POWER_BASE_OPERATOR,     std::make_shared<OperatorPowerBase<A>>());
        operators.append(LOGARITHM_BASE_OPERATOR, std::make_shared<OperatorLogarithmBase<A>>());
        operators.append(LOGARITHM_10_OPERATOR,   std::make_shared<OperatorLogarithm10<A>>());
        operators.append(LOGARITHM_OPERATOR,      std::make_shared<OperatorLogarithm<A>>());
        operators.append(EXPONENT_OPERATOR,       std::make_shared<OperatorExponent<A>>());
        operators.append(PARENTHESES_OPERATOR,    std::make_shared<OperatorParentheses<A>>()); // should be last of group operators
        
        operators.append(CONDITION_OPERATOR,      std::make_shared<OperatorCondition<A>>());
        
        operators.append(POWER_OPERATOR,          std::make_shared<OperatorPower<A>>());

        operators.append(MODULO_OPERATOR,         std::make_shared<OperatorModulo<A>>());
        operators.append(MULTIPLY_OPERATOR,       std::make_shared<OperatorMultiply<A>>());
        operators.append(DIVIDE_OPERATOR,         std::make_shared<OperatorDivide<A>>());
        operators.append(ADD_OPERATOR,            std::make_shared<OperatorAdd<A>>());
        operators.append(SUBTRACT_OPERATOR,       std::make_shared<OperatorSubtract<A>>());
        
        operators.append(EQUAL_OPERATOR,          std::make_shared<OperatorEqual<A>>());
        operators.append(NOT_EQUAL_OPERATOR,      std::make_shared<OperatorNotEqual<A>>());
        
        operators.append(NOT_OPERATOR,            std::make_shared<OperatorNot<A>>()); // needs to be after NOT_EQUAL
        
        operators.append(LOWER_EQUAL_OPERATOR,    std::make_shared<OperatorLowerEqual<A>>());
        operators.append(GREATER_EQUAL_OPERATOR,  std::make_shared<OperatorGreaterEqual<A>>());
        operators.append(LOWER_OPERATOR,          std::make_shared<OperatorLower<A>>());
        operators.append(GREATER_OPERATOR,        std::make_shared<OperatorGreater<A>>());
        
        operators.append(AND_OPERATOR,            std::make_shared<OperatorAnd<A>>());
        operators.append(OR_OPERATOR,             std::make_shared<OperatorOr<A>>());
    }
};

}

#endif // EXS_SOLVER_H
