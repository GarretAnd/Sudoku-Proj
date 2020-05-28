# CS50 Final Project
## CS50 Spring 2020

### common

The common directory stores `libsudoku`, which contains a variety of functions that are shared by the sudoku creator and solver, and `random`, which houses random-oriented functions.

`libsudoku` can perform the following tasks:

1. Create an empty sudoku puzzle initialized full of zeroes (`sudoku_new`)
2. Edit the value at an i,j coordinate of the puzzle (`sudoku_edit`)
3. Get the element at an i,j coordinate (`sudoku_get`)
4. Copy a puzzle (`sudoku_copy`)
5. Check if two puzzles are identical (`sudoku_equal`)
6. Load a puzzle from `stdin` to a sudoku structure (`sudoku_load`)
7. Print a sudoku to `stdout` (`sudoku_print`)
8. Delete a sudoku structure (`sudoku_delete`)
9. Check if a row, column, and box is valid (`sudoku_isvalid`)

`random` can perform the following tasks:

1. Initialize the random seed (`gen_init`)
2. Return a random number (`rand_num`)

### Usage

`libsudoku` itself is meant to be called by outside modules, and thus does not have an executable. `libsudokutest`, on the other hand, can be executed by calling `./libsudokutest`

### Assumptions

No assumptions were made beyond those that were clear from the spec.

### Compilation

To compile, call `make`. To test, call `make test`. To clean, call `make clean`.
