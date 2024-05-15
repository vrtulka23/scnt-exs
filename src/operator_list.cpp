#include "main.h"

OperatorListClass::OperatorListClass() {
  operators[ADD_OPERATOR]      = new OperatorAdd();
  operators[SUBTRACT_OPERATOR] = new OperatorSubtract();
  operators[MULTIPLY_OPERATOR] = new OperatorMultiply();
  operators[DIVIDE_OPERATOR]   = new OperatorDivide();
}

OperatorListClass::OperatorListClass(OperatorsType &o): operators(o) {
}

OperatorListClass::~OperatorListClass() {
  for (auto o : operators) {
    delete o.second;
  }  
}

OperatorInterface* OperatorListClass::select(OperatorType otype) {
  OperatorsType::const_iterator it = operators.find(otype);
  return it->second;
}