#ifndef EXS_STEP_LIST_H
#define EXS_STEP_LIST_H

#include <vector>
#include <memory>

namespace exs {

typedef std::vector<std::pair<OperationType, std::vector<OperatorType>>> StepListType;

class StepList {
public:
  StepListType steps;
  void append(OperationType t, std::vector<OperatorType> s) {
    steps.push_back({t, s});
  };
};

}
  
#endif // EXS_STEP_LIST_H
