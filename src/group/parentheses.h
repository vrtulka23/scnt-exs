#ifndef OPERATOR_PARENTHESES_H
#define OPERATOR_PARENTHESES_H

template <class A>
class OperatorParentheses: public OperatorGroup<A, 1> {
public:
  OperatorParentheses(): OperatorGroup<A, 1>("par","(",PARENTHESES_OPERATOR) {}
};

#endif // OPERATOR_PARENTHESES_H