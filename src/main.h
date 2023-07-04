template<class T>
class AtomBase {
public:
  T value;
  AtomBase(T v);
  AtomBase<T> operator+(AtomBase<T> const& obj);
  AtomBase<T> operator-(AtomBase<T> const& obj);
  AtomBase<T> operator*(AtomBase<T> const& obj);
  AtomBase<T> operator/(AtomBase<T> const& obj);
  AtomBase<T> operator-();
  AtomBase<T> pow(T exp);
  AtomBase<T> log();
  AtomBase<T> log10();
  AtomBase<T> sqrt();
  AtomBase<T> sin();
  AtomBase<T> cos();
  AtomBase<T> tan();
  AtomBase<T> operator&&(AtomBase<T> const& obj);
  AtomBase<T> operator||(AtomBase<T> const& obj);
  AtomBase<T> operator!();
  AtomBase<T> operator==(AtomBase<T> const& obj);
  AtomBase<T> operator!=(AtomBase<T> const& obj);
  AtomBase<T> operator<=(AtomBase<T> const& obj);
  AtomBase<T> operator>=(AtomBase<T> const& obj);
  AtomBase<T> operator<(AtomBase<T> const& obj);
  AtomBase<T> operator>(AtomBase<T> const& obj);
  void print();
};

#include "AtomBaseClass.h"

class Expression {
public:
  std::string left;
  std::string expr;
  std::string right;
  Expression(std::string e);
  void shift(int n = 1);
  void remove(std::string s);
  std::string pop_left();
  void print();
};
