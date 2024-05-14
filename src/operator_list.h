#ifndef OPERATOR_LIST_H
#define OPERATOR_LIST_H

#include <unordered_map>

typedef std::unordered_map<OperatorType, OperatorInterface*> OperatorsType;

class OperatorListClass {
public:
  OperatorsType map;
  OperatorListClass();
  OperatorListClass(OperatorsType &m);
  ~OperatorListClass();
  OperatorInterface* find(OperatorType otype);
};

extern OperatorListClass OperatorList;

#endif // OPERATOR_LIST_H
