#ifndef OPERATOR_LIST_H
#define OPERATOR_LIST_H

#include <unordered_map>
#include <memory>

typedef std::unordered_map<OperatorType, OperatorBase*> OperatorListType;

class OperatorList {
public:
  OperatorListType operators;
  OperatorList();
  OperatorList(OperatorListType &o);
  ~OperatorList();
  OperatorBase* select(OperatorType otype);
};

#endif // OPERATOR_LIST_H
