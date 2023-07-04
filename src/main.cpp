#include <iostream>
#include "main.h"

int main() {

  AtomBase<double> a(23.0);
  AtomBase<double> b(33.0);
  AtomBase<double> c = a+b;
  c.print();
  c = b-a;
  c.print();
  
  AtomBase<bool> d(false);
  d.print();

  Expression e("Hello world");
  e.print();
  e.shift();
  e.print();
  e.remove("e");
  e.print();
  std::cout << e.pop_left() << std::endl;
  e.print();
  
  return 0;
}
