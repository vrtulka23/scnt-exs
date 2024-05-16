#ifndef ATOM_H
#define ATOM_H

#include <math.h>

class Atom {
public:
  std::variant<int, float, bool> value;
  Atom(std::string v) {
    //std::cout << "'" << v << "'" << std::endl;
    value = std::stof(v); 
  };
  
  void add(Atom *other) {
      value = std::get<float>(value) + std::get<float>(other->value);
  }
  void subtract(Atom *other) {
      value = std::get<float>(value) - std::get<float>(other->value);
  }
  void negate() {
      value = -std::get<float>(value);
  }
  void multiply(Atom *other) {
      value = std::get<float>(value) * std::get<float>(other->value);
  }
  void divide(Atom *other) {
      value = std::get<float>(value) / std::get<float>(other->value);
  }
  void power(Atom *other) {
      value = pow(std::get<float>(value), std::get<float>(other->value));
  }
  
  void equal(Atom *other) {
      value = std::get<float>(value) == std::get<float>(other->value);
  }
  void not_equal(Atom *other) {
      value = std::get<float>(value) != std::get<float>(other->value);
  }
  void lower_equal(Atom *other) {
      value = std::get<float>(value) <= std::get<float>(other->value);
  }
  void greater_equal(Atom *other) {
      value = std::get<float>(value) >= std::get<float>(other->value);
  }
  void lower(Atom *other) {
      value = std::get<float>(value) < std::get<float>(other->value);
  }
  void greater(Atom *other) {
      value = std::get<float>(value) > std::get<float>(other->value);
  }
};

#endif // ATOM_H