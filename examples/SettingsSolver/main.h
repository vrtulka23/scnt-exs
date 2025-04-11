#include "../../src/exs.h"

struct Settings {
  std::string symbol;
  int value;
  std::array<int,5> options;
};

enum CustomOperatorType {
  SELECT_OPERATOR = exs::NUM_OPERATOR_TYPES
};

class CustomAtom: public exs::AtomBase<int> {
 public:
  CustomAtom(CustomAtom &a): AtomBase(a) {};
  CustomAtom(int v): AtomBase(v) {}; 
  static int from_string(std::string s, Settings* set);
  std::string to_string();
  void math_add(CustomAtom *other);
  void math_subtract(CustomAtom *other);
  void math_negate();
};

class OperatorSelect: public exs::OperatorGroup<CustomAtom, 1, Settings> {
 public:
  OperatorSelect();
  void operate_group(exs::TokenListBase<CustomAtom> *tokens, Settings* settings);
};
