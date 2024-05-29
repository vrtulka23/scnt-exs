# Expression Solver

General purpose solver of mathematical expressions in C++

## Introduction

This project is a reimplementation of already existing solver into the C++ language.
Original version of the code, written in Python, is available in the [scinumtools.solver](https://github.com/vrtulka23/scinumtools/tree/main/src/scinumtools/solver) repository.
In the future this version is supposed to replace the original and further improve performance of the **scinumtools** package.

## Setup

For purpouse of developing and debugging we created a simple **setup.sh** shell script that implements the most used routines: cleaning, building, testing and running of the code. For more instructions how to use this script refere to its help section:

```bash
./setup.sh -h
```

## Example of use

Equation solver is implemented in C++ as a header file template library.
The main class ``Solver`` takes as a template argument the ``Atom`` class.
Standard implementation of an ``Atom`` is provided in the code, nevertheless, it can be easily modified by the user.
Source code of the following simple example can be found in the [examples/DefaultSolver](https://github.com/vrtulka23/scinumtools/tree/main/examples/DefaultSolver) directory.

```cpp
#include "../../src/exs.h"

using namespace exs;

int main() {
  Solver<Atom> solver;
  Atom atom = solver.solve("23 * 34.5 + 4");
  atom.print();
}
```

This example can be compiled and run using the ``setup.sh`` script mentioned above

```bash
./setup.sh -c -b -r DefaultSolver
```

and will print ``797.5`` into the terminal.

Other, more comprehensive examples are provided in the ``example`` directory, and additional code tests are implemented in the ``tests`` directory.
