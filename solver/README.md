# CS50 Final Project
## CS50 Spring 2020

### solver

The solver directory stores `solver.c`, which is responsible for solving sudoku puzzles.

`sovler` can perform the following tasks:

1. Solve a puzzle (with preference to low values)
2. Solve a puzzle with random preference to values
3. State if a puzzle has one unique solution or not
    - to test for unique solutions the solver solves the puzzle with preference given to low values and with preference given to high values then checks whether or not the two solutions are different.

### Usage

`solver.c` is meant to be called by outside modules, and thus does not have an exectuable (other than for unit testing).

solver exports the following functions through solver.h
```c
/*
 * finds a solution for given sudoku and puts solution into said sudoku
 * returns true if a solution was found, false otherwise
 */
bool solve_puzzle(sudoku_t *sudoku);

/*
 * returns true if the given sudoku has exactly one valid solution, false otherwise
 * Note: does not solve given sudoku, just checks for solutions.
 */
bool unique_solution(sudoku_t *sudoku);

/*
 * finds a solution for given sudoku but gives random preference to numbers chose if there is more than one solution available
 * returns true if solution was found, false otherwise
 */
bool solve_puzzle_random(sudoku_t *sudoku);
```

### Assumptions

No assumptions were made beyond those that were clear from the spec.

### Compilation

To compile, call `make`. To clean, call `make clean`. To test call make test
