template<class T>
class AtomBase {
public:
  T value;
  AtomBase(T v);
  AtomBase<T> operator+(AtomBase<T> const& obj);
  AtomBase<T> operator-(AtomBase<T> const& obj);
  AtomBase<T> operator*(AtomBase<T> const& obj);
  AtomBase<T> operator/(AtomBase<T> const& obj);
  AtomBase<T> pow(T exp);
  AtomBase<T> operator-();
  AtomBase<T> log();
  AtomBase<T> log10();
  AtomBase<T> sqrt();
  AtomBase<T> sin();
  AtomBase<T> cos();
  AtomBase<T> tan();
  void print();
};

#include "AtomBaseClass.h"
