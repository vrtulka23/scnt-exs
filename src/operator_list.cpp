#include "main.h"

OperatorListClass::OperatorListClass() {
  map[ADD_OPERATOR]      = new OperatorAdd();
  map[SUBTRACT_OPERATOR] = new OperatorSubtract();
  map[MULTIPLY_OPERATOR] = new OperatorMultiply();
  map[DIVIDE_OPERATOR]   = new OperatorDivide();
}

OperatorListClass::OperatorListClass(OperatorsType &m): map(m) {
}

OperatorListClass::~OperatorListClass() {
  for (auto o : map) {
    delete o.second;
  }  
}

OperatorInterface* OperatorListClass::find(OperatorType otype) {
  OperatorsType::const_iterator it = map.find(otype);
  return it->second;
}

OperatorListClass OperatorList;
