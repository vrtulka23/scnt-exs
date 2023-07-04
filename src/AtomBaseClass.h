#include <math.h>
#include <stdexcept> 

template <class T>
AtomBase<T>::AtomBase(T v) {
  value = v;
}

template <class T>
AtomBase<T> AtomBase<T>::operator+(AtomBase<T> const& obj) {
  return AtomBase<T>(value + obj.value);
}

template <class T>
AtomBase<T> AtomBase<T>::operator-(AtomBase<T> const& obj) {
  return AtomBase<T>(value - obj.value);
}

template <class T>
AtomBase<T> AtomBase<T>::operator*(AtomBase<T> const& obj) {
  return AtomBase<T>(value * obj.value);
}

template <class T>
AtomBase<T> AtomBase<T>::operator/(AtomBase<T> const& obj) {
  return AtomBase<T>(value / obj.value);
}

template <class T>
AtomBase<T> AtomBase<T>::operator-() {
  return AtomBase<T>(-value);
}

template <class T>
AtomBase<T> AtomBase<T>::pow(T exp) {
  return AtomBase<T>(::pow(value, exp));
}

template <class T>
AtomBase<T> AtomBase<T>::log() {
  return AtomBase<T>(::log(value));
}

template <class T>
AtomBase<T> AtomBase<T>::log10() {
  return AtomBase<T>(::log10(value));
}

template <class T>
AtomBase<T> AtomBase<T>::sqrt() {
  return AtomBase<T>(::sqrt(value));
}

template <class T>
AtomBase<T> AtomBase<T>::sin() {
  return AtomBase<T>(::sin(value));
}

template <class T>
AtomBase<T> AtomBase<T>::cos() {
  return AtomBase<T>(::cos(value));
}

template <class T>
AtomBase<T> AtomBase<T>::tan() {
  return AtomBase<T>(::tan(value));
}

template <class T>
AtomBase<T> AtomBase<T>::operator&&(AtomBase<T> const& obj) {
  return AtomBase<T>(value && obj.value);
}

template <class T>
AtomBase<T> AtomBase<T>::operator||(AtomBase<T> const& obj) {
  return AtomBase<T>(value || obj.value);
}

template <class T>
AtomBase<T> AtomBase<T>::operator!() {
  return AtomBase<T>(!value);
}

template <class T>
AtomBase<T> AtomBase<T>::operator==(AtomBase<T> const& obj) {
  return AtomBase<T>(value == obj.value);
}

template <class T>
AtomBase<T> AtomBase<T>::operator!=(AtomBase<T> const& obj) {
  return AtomBase<T>(value != obj.value);
}

template <class T>
AtomBase<T> AtomBase<T>::operator<=(AtomBase<T> const& obj) {
  return AtomBase<T>(value <= obj.value);
}

template <class T>
AtomBase<T> AtomBase<T>::operator>=(AtomBase<T> const& obj) {
  return AtomBase<T>(value >= obj.value);
}

template <class T>
AtomBase<T> AtomBase<T>::operator<(AtomBase<T> const& obj) {
  return AtomBase<T>(value < obj.value);
}

template <class T>
AtomBase<T> AtomBase<T>::operator>(AtomBase<T> const& obj) {
  return AtomBase<T>(value > obj.value);
}

template <class T>
void AtomBase<T>::print() {
  std::cout << value << std::endl;
}
