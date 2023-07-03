#include <iostream>
#include "main.h"

int main() {

  AtomBase<double> a(23.0);
  AtomBase<double> b(33.0);
  AtomBase<double> c = a+b;
  c.print();
  c = b-a;
  c.print();

  AtomBase<bool> d(true);
  
  return 0;
}
