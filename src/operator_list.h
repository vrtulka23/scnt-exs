#ifndef OPERATOR_LIST_H
#define OPERATOR_LIST_H

#include <unordered_map>
#include <memory>

typedef std::unordered_map<OperatorType, std::shared_ptr<OperatorBase>> OperatorListType;

class OperatorList {
public:
  OperatorListType operators;
  OperatorBase* select(OperatorType otype) {
    auto it = operators.find(otype);
    if (it != operators.end()) {
      return &(*(it->second));
    } else {
      throw std::logic_error("Selecting non existing operator");
    }
  };
  void append(OperatorType t, std::shared_ptr<OperatorBase> o) {
    operators[t] = o;
  };
};

#endif // OPERATOR_LIST_H
