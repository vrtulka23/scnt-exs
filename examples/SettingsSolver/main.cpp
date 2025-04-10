#include <memory>

#import "main.h"

int main() {

  Settings settings({"?", 5});

  // modifying default operator symbols
  exs::OperatorList<CustomAtom> operators;
  operators.append(exs::ADD_OPERATOR,      std::make_shared<exs::OperatorAdd<CustomAtom>>());
  operators.append(exs::SUBTRACT_OPERATOR, std::make_shared<exs::OperatorSubtract<CustomAtom>>());
  
  // changing default operation steps
  exs::StepList steps;
  steps.append(exs::BINARY_OPERATION,     {exs::ADD_OPERATOR, exs::SUBTRACT_OPERATOR});
  
  exs::Solver<CustomAtom, Settings> solver(operators, steps, settings);
  CustomAtom atom = solver.solve("2 + ? - 3");
  atom.print();

  /*
   * Equivalent c++ notation:
   * 2 + 5 - 3 = 4
   */
  
}

