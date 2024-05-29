#ifndef EXS_OPERATOR_PARENTHESES_H
#define EXS_OPERATOR_PARENTHESES_H

namespace exs {
  
template <class A>
class OperatorParentheses: public OperatorGroup<A, 1> {
public:
  OperatorParentheses(): OperatorGroup<A, 1>("par","(",PARENTHESES_OPERATOR) {}
};

}

#endif // EXS_OPERATOR_PARENTHESES_H
