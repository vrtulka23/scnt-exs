#ifndef OPERATOR_LIST_H
#define OPERATOR_LIST_H

#include <unordered_map>
#include <memory>
#include <vector>

namespace exs {
  
template <class A>
class OperatorList {
  typedef std::unordered_map<OperatorType, std::shared_ptr<OperatorBase<A>>> OperatorListType;
public:
  OperatorListType operators;
  std::vector<OperatorType> order;
  OperatorBase<A>* select(OperatorType otype) {
    auto it = operators.find(otype);
    if (it != operators.end()) {
      return &(*(it->second));
    } else {
      throw std::logic_error("Selecting non existing operator");
    }
  };
  void append(OperatorType t, std::shared_ptr<OperatorBase<A>> o) {
    operators[t] = o;
    order.push_back(t);
  };
};

}
  
#endif // OPERATOR_LIST_H
