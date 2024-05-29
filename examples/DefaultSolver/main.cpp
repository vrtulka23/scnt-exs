#include "../../src/exs.h"

using namespace exs;

int main() {
  Solver<Atom> solver;
  Atom atom = solver.solve("23 * 34.5 + 4");
  atom.print();
}

