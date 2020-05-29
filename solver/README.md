# CS50 Final Project
## CS50 Spring 2020

### solver

The solver directory stores `solver.c`, which is responsible for solving sudoku puzzles.

`sovler` can perform the following tasks:

1. Solve a puzzle
2. Solve a puzzle randomly
3. State if a puzzle has one unique solution or not
    - to test for unique solutions the solver solves the puzzle with preference given to low values and with preference given to high values then checks whether or not the two solutions are different.

### Usage

`solver.c` is meant to be called by outside modules, and thus does not have an exectuable (other than for unit testing).

### Assumptions

No assumptions were made beyond those that were clear from the spec.

### Compilation

To compile, call `make`. To clean, call `make clean`. To test call make test
