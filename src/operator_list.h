#ifndef OPERATOR_LIST_H
#define OPERATOR_LIST_H

#include <unordered_map>

typedef std::unordered_map<OperatorType, OperatorInterface*> OperatorListType;

class OperatorListClass {
public:
  OperatorListType operators;
  OperatorListClass();
  OperatorListClass(OperatorListType &o);
  ~OperatorListClass();
  OperatorInterface* select(OperatorType otype);
  void insert(OperatorType t, OperatorInterface *o);
};

#endif // OPERATOR_LIST_H
