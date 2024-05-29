# Expression Solver (EXS)

General purpose solver of textual expressions in C++

## Introduction

This project is a reimplementation of already existing [Expression Solver](https://vrtulka23.github.io/scinumtools/solver/index.html) into the C++ language.
Original version of the code, written in Python, is available in the [scinumtools.solver](https://github.com/vrtulka23/scinumtools/tree/main/src/scinumtools/solver) repository.
In the future, this version is supposed to replace the original and further improve performance of the **scinumtools** package.

## Setup

For purpose of developing and debugging we created a simple **setup.sh** shell script that implements the most used routines: cleaning, building, testing, and running of the code. For more instructions how to use this script refer to its help section:

```bash
./setup.sh -h
```

## Example of use

The Equation Solver is implemented in C++ as a header file template library.
The main class ``Solver`` takes as a template argument the ``Atom`` class.
A standard implementation of an ``Atom`` is provided in the code, nevertheless, it can be easily modified by the user.
Source code of the following simple example can be found in the [examples/DefaultSolver](https://github.com/vrtulka23/exs-cpp/tree/main/examples/DefaultSolver) directory.

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

The list of all default operations and their order is initialized in the [``Solver`` class](https://github.com/vrtulka23/exs-cpp/blob/main/src/solver.h).
However, individual operators and their order can be easily modified as in the example below.

```cpp
// modifying default operator symbols
OperatorList<Atom> operators;
operators.append(NOT_OPERATOR, std::make_shared<OperatorNot<Atom>>("N"));
operators.append(AND_OPERATOR, std::make_shared<OperatorAnd<Atom>>("A"));
operators.append(OR_OPERATOR,  std::make_shared<OperatorOr<Atom>>("O"));

// changing default operation steps
StepList steps;
steps.append(BINARY_OPERATION, {OR_OPERATOR});
steps.append(BINARY_OPERATION, {AND_OPERATOR});
steps.append(UNARY_OPERATION,  {NOT_OPERATOR});

Solver<Atom> solver(operators, steps);
Atom atom = solver.solve("N false A false O true");
atom.print();
```

The corresponding example can be compiled using the following command.

```bash
./setup.sh -c -b -r ModifiedSolver
```

More comprehensive examples (e.g. custom ``Atom`` and operator classes) are provided in the ``example`` directory, and additional code tests are implemented in the ``tests`` directory.
