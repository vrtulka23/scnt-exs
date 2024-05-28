#ifndef ATOM_H
#define ATOM_H

#include <regex>
#include <math.h>
#include <stdexcept>
#include <cmath>
#include <sstream>

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
      std::regex rx("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?((e|E)((\\+|-)?)[[:digit:]]+)?");
      if (std::regex_match(v, rx)) {
        value=std::stof(v);
      } else {
        throw std::logic_error("Atom string could not be parsed, probably due to unknown symbol or operator: "+v);
      }
    }
  };
  std::string to_string() {
    if (std::holds_alternative<float>(value)) {
      std::stringstream str;
      str << std::get<float>(value) << std::scientific;
      return str.str();
    } else {
      if (std::get<bool>(value)==0) return "false";
      else return "true";
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
  void math_modulo(Atom *other) {
    value = (float)((int)std::get<float>(value) % (int) std::get<float>(other->value));
  }

  // Argument math operators
  void math_exponent() {
      value = std::exp(std::get<float>(value));
  }
  void math_logarithm() {
      value = std::log(std::get<float>(value));
  }
  void math_logarithm_10() {
      value = std::log10(std::get<float>(value));
  }
  void math_logarithm_base(Atom *other) {
      value = std::log(std::get<float>(value)) / std::log(std::get<float>(other->value));
  }
  void math_power_base(Atom *other) {
      value = pow(std::get<float>(value), std::get<float>(other->value));
  }
  void math_square_root() {
      value = std::sqrt(std::get<float>(value));
  }
  void math_sinus() {
      value = std::sin(std::get<float>(value));
  }
  void math_cosinus() {
      value = std::cos(std::get<float>(value));
  }
  void math_tangens() {
      value = std::tan(std::get<float>(value));
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
  
};

#endif // ATOM_H
