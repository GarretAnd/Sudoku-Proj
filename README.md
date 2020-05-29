# CS50 Final Project
## cs50maybecsmajor
## CS50 Spring 2020

### sudoku

`sudoku.c` combines the modules found in `common`, `creator`, and `solver`. This module has the ability to create new puzzles with a unique solution, as well as solve puzzles that have a solution.

### Usage

`sudoku.c` can be called in two different ways. Regardless of which mode is used, only one command line argument is permitted:

*create*

`./sudoku create` prints a new sudoku puzzle with one unique solution to `stdout`

*solve*

`./sudoku solve` will read a sudoku puzzle from `stdin`, and print the solved version (if it exists) to `stdout`.

Exit Codes:
- 0: Exited normally, no problems encountered
- 1: Invalid number of command line arguments
- 2: Invalid specification of mode (create or solve)
- 3: Unable to create sudoku puzzle (out of memory)
- 4: Unable to solve given sudoku puzzle

### Assumptions

No assumptions were made beyond those that were clear from the spec.

### Compilation

To compile, call `make`. To test, call `make test`. To clean, call `make clean`.
