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
  OperatorListType::const_iterator it = operators.find(otype);
  return it->second;
}

void OperatorListClass::insert(OperatorType t, OperatorBase *o) {
  operators[t] = o;
}