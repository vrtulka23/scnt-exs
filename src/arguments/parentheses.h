#ifndef OPERATOR_PARENTHESES_H
#define OPERATOR_PARENTHESES_H

template <class A>
class OperatorParentheses: public OperatorArguments<A, 1> {
public:
  OperatorParentheses(): OperatorArguments<A, 1>("par","(",PARENTHESES_OPERATOR) {}
};

#endif // OPERATOR_PARENTHESES_H