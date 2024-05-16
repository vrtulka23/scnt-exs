#ifndef OPERATOR_LIST_H
#define OPERATOR_LIST_H

#include <unordered_map>

typedef std::unordered_map<OperatorType, OperatorBase*> OperatorListType;

class OperatorListClass {
public:
  OperatorListType operators;
  OperatorListClass();
  OperatorListClass(OperatorListType &o);
  ~OperatorListClass();
  OperatorBase* select(OperatorType otype);
};

#endif // OPERATOR_LIST_H
