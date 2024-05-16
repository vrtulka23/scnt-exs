#include "main.h"

OperatorList::OperatorList() {
  operators[ADD_OPERATOR]      = new OperatorAdd();
  operators[SUBTRACT_OPERATOR] = new OperatorSubtract();
  operators[MULTIPLY_OPERATOR] = new OperatorMultiply();
  operators[DIVIDE_OPERATOR]   = new OperatorDivide();
  operators[POWER_OPERATOR]    = new OperatorPower();
}

OperatorList::OperatorList(OperatorListType &o): operators(o) {
}

OperatorList::~OperatorList() {
  for (auto o : operators) {
    delete o.second;
  }  
}

OperatorBase* OperatorList::select(OperatorType otype) {
  OperatorListType::iterator it = operators.find(otype);
  if (it != operators.end()) {
    return it->second;
  } else {
    throw std::logic_error("Selecting non existing operator");
  }
}