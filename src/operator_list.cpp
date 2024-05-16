#include "main.h"

OperatorListClass::OperatorListClass() {
  operators[ADD_OPERATOR]      = new OperatorAdd();
  operators[SUBTRACT_OPERATOR] = new OperatorSubtract();
  operators[MULTIPLY_OPERATOR] = new OperatorMultiply();
  operators[DIVIDE_OPERATOR]   = new OperatorDivide();
  operators[POWER_OPERATOR]    = new OperatorPower();
}

OperatorListClass::OperatorListClass(OperatorListType &o): operators(o) {
}

OperatorListClass::~OperatorListClass() {
  for (auto o : operators) {
    delete o.second;
  }  
}

OperatorBase* OperatorListClass::select(OperatorType otype) {
  OperatorListType::iterator it = operators.find(otype);
  if (it != operators.end()) {
    return it->second;
  } else {
    throw std::logic_error("Selecting non existing operator");
  }
}