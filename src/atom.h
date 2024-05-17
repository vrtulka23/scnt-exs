#ifndef ATOM_H
#define ATOM_H

#include <regex>
#include <math.h>
#include <stdexcept>

class Atom {
public:
  std::variant<float, bool> value;
  Atom(std::string v) {
    if (v=="true") {
      value=true; 
    } else if (v=="false") {
      value=false;
    } else {
      std::regex rx(R"((?:^|\s)([+-]?[[:digit:]]+(?:\.[[:digit:]]+)?)(?=$|\s))");
      if (std::regex_match(v, rx)) {
        value=std::stof(v);
      } else {
        throw std::logic_error("Atom has a wrong format: "+v);
      }
    }
  };
  
  // Math operations
  void math_add(Atom *other) {
      value = std::get<float>(value) + std::get<float>(other->value);
  }
  void math_subtract(Atom *other) {
      value = std::get<float>(value) - std::get<float>(other->value);
  }
  void math_negate() {
      value = -std::get<float>(value);
  }
  void math_multiply(Atom *other) {
      value = std::get<float>(value) * std::get<float>(other->value);
  }
  void math_divide(Atom *other) {
      value = std::get<float>(value) / std::get<float>(other->value);
  }
  void math_power(Atom *other) {
      value = pow(std::get<float>(value), std::get<float>(other->value));
  }
  
  // Comparison operations
  void comparison_equal(Atom *other) {
      value = std::get<float>(value) == std::get<float>(other->value);
  }
  void comparison_not_equal(Atom *other) {
      value = std::get<float>(value) != std::get<float>(other->value);
  }
  void comparison_lower_equal(Atom *other) {
      value = std::get<float>(value) <= std::get<float>(other->value);
  }
  void comparison_greater_equal(Atom *other) {
      value = std::get<float>(value) >= std::get<float>(other->value);
  }
  void comparison_lower(Atom *other) {
      value = std::get<float>(value) < std::get<float>(other->value);
  }
  void comparison_greater(Atom *other) {
      value = std::get<float>(value) > std::get<float>(other->value);
  }
  
  // Logical operations
  void logical_not() {
      value = !std::get<bool>(value);
  }
  void logical_and(Atom *other) {
      value = std::get<bool>(value) && std::get<bool>(other->value);
  }
  void logical_or(Atom *other) {
      value = std::get<bool>(value) || std::get<bool>(other->value);
  }
};

#endif // ATOM_H