#ifndef EXS_OPERATOR_PARENTHESES_H
#define EXS_OPERATOR_PARENTHESES_H

namespace exs {
  
template <class A, typename S = EmptySettings>
class OperatorParentheses: public OperatorGroup<A, 1, S> {
public:
  OperatorParentheses(): OperatorGroup<A, 1, S>("par","(",PARENTHESES_OPERATOR) {}
};

}

#endif // EXS_OPERATOR_PARENTHESES_H
