#ifndef OPERATOR_LIST_H
#define OPERATOR_LIST_H

#include <unordered_map>

typedef std::unordered_map<OperatorType, OperatorInterface*> OperatorsType;

class OperatorListClass {
public:
  OperatorsType operators;
  OperatorListClass();
  OperatorListClass(OperatorsType &o);
  ~OperatorListClass();
  OperatorInterface* select(OperatorType otype);
};

#endif // OPERATOR_LIST_H
