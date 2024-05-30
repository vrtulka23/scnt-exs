#include "../../src/exs.h"

#include <memory>

enum CustomOperatorType {
  LENGTH_OPERATOR = NUM_OPERATOR_TYPES
};

typedef std::variant<std::string, bool, size_t> AtomValueType;

class CustomAtom: public exs::AtomBase<AtomValueType> {
public:
  CustomAtom(CustomAtom &a): AtomBase(a) {};
  CustomAtom(AtomValueType v): AtomBase(v) {};  
  static AtomValueType parse(std::string s) {
    return s;
  }
  std::string to_string() {
    if (std::holds_alternative<std::string>(value)) {
      return std::get<std::string>(value);
    } else if (std::holds_alternative<size_t>(value)) {
      return std::to_string(std::get<size_t>(value));
    } else {
      if (std::get<bool>(value)==0) return "false";
      else return "true";
    }
  }
  void comparison_lower(CustomAtom *other) {
    size_t value_this;
    size_t value_other;
    if (std::holds_alternative<std::string>(value)) {
      value_this = std::get<std::string>(value).size();
    } else {
      value_this = std::get<size_t>(value);
    }
    if (std::holds_alternative<std::string>(other->value)) {
      value_other = std::get<std::string>(other->value).size();
    } else {
      value_other = std::get<size_t>(other->value);
    }
    value = value_this < value_other;
  }
  void custom_length() {
    value = std::get<std::string>(value).size();
  }
};

class OperatorLength: public exs::OperatorGroup<CustomAtom, 1> {
public:
  OperatorLength(): OperatorGroup<CustomAtom, 1>("len","len(",GREATER_OPERATOR) {}
  void operate_group(exs::TokenListBase<CustomAtom> *tokens) {
    exs::Token<CustomAtom> group1 = tokens->get_left();
    group1.atom->custom_length();
    tokens->put_left(group1);
  };
};


int main() {

  // modifying default operator symbols
  exs::OperatorList<CustomAtom> operators;
  operators.append(LOWER_OPERATOR, std::make_shared<exs::OperatorLower<CustomAtom>>());
  operators.append(GREATER_OPERATOR, std::make_shared<OperatorLength>());

  // changing default operation steps
  exs::StepList steps;
  steps.append(GROUP_OPERATION, {GREATER_OPERATOR});
  steps.append(BINARY_OPERATION, {LOWER_OPERATOR});
  
  exs::Solver<CustomAtom> solver(operators, steps);
  CustomAtom atom = solver.solve("apple < len(hospital)");
  atom.print();

  /*
   * Equivalent c++ notation:
   * std::string("apple").size() < std::string("hospital").size() == true
   */
}

