# CS50 Final Project
## CS50 Winter 2020

### common

The common directory stores `libsudoku`, which contains a variety of functions that are shared by the sudoku creator and solver.

`libsudoku` can perform the following tasks:

1. Create an empty sudoku puzzle initialized full of zeroes (`sudoku_new`)
2. Edit the value at an i,j coordinate of the puzzle (`sudoku_edit`)
3. Print a sudoku to `stdout` (`sudoku_print`)
4. Delete a sudoku structure (`sudoku_delete`)
5. Check if a row, column, and box is valid (`sudoku_isvalid`)

### Usage

`libsudoku` itself is meant to be called by outside modules, and thus does not have an executable. `libsudokutest`, on the other hand, can be executed by calling `./libsudokutest`

### Assumptions

No assumptions were made beyond those that were clear from the spec.

### Compilation

To compile, call `make`. To test, call `make test`. To clean, call `make clean`.
