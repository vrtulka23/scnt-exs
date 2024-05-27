#ifndef ATOM_H
#define ATOM_H

#include <regex>
#include <math.h>
#include <stdexcept>
#include <cmath>

class Atom {
public:
  std::variant<float, bool> value;
  Atom(std::variant<float, bool> v): value(v) {};
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
        throw std::logic_error("Atom string could not be parsed: "+v);
      }
    }
  };
  std::string to_string() {
    if (std::holds_alternative<float>(value)) {
      return std::to_string(std::get<float>(value));
    } else {
      return std::to_string(std::get<bool>(value));
    }
  }
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
  
  // Conditional operator
  void condition(Atom *option1, Atom *option2) {
      value = std::get<bool>(value) ? std::get<float>(option1->value) : std::get<float>(option2->value);
  }
  
  // Argument operators
  void group_exponent() {
      value = std::exp(std::get<float>(value));
  }
  void group_logarithm() {
      value = std::log(std::get<float>(value));
  }
  void group_logarithm_10() {
      value = std::log10(std::get<float>(value));
  }
  void group_logarithm_base(Atom *other) {
      value = std::log(std::get<float>(value)) / std::log(std::get<float>(other->value));
  }
  void group_power_base(Atom *other) {
      value = pow(std::get<float>(value), std::get<float>(other->value));
  }
  void group_square_root() {
      value = std::sqrt(std::get<float>(value));
  }
  void group_sinus() {
      value = std::sin(std::get<float>(value));
  }
  void group_cosinus() {
      value = std::cos(std::get<float>(value));
  }
  void group_tangens() {
      value = std::tan(std::get<float>(value));
  }
};

#endif // ATOM_H
