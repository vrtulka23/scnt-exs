# Equation Solver

General purpose solver of mathematical expressions in C++

## Introduction

This project is a reimplementation of already existing solver into the C++ language.
Original version of the code, written in Python, is available in the [scinumtools.solver](https://github.com/vrtulka23/scinumtools/tree/main/src/scinumtools/solver) repository.
In the future this version is supposed to replace the original and hence further improve the performance of the **scinumtools** package.

## Setup

For purpouse of developing and debugging we created a simple **setup.sh** shell script that implements the most used routines: cleaning, building, testing and running of the code. For more instructions how to use this script run it with the following flag:

```bash
./setup.sh -h
```

## Example of use

Equation solver is implemented in C++ as a header file template library.
The main class ``Solver`` takes as a template argument an ``Atom`` class.
Standard implementation of an ``Atom`` class is provided in the code, nevertheless, it can be easily modified by the user.

```cpp
Solver<Atom> solver;
float result = solver.solve("23 * 34.5 + 4");
std::cout << result << std::end;
```

The example above will print ``797.5`` into the console.

