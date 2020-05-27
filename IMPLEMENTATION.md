# cs50maybecsmajor, CS50 Final Project Spring 2020

## Sudoku

`sudoku` takes one argument from the command line, either `create` or `solve`. If `create` is specified, a random unsolved sudoku puzzle with one unique solution is generated. If `solve` is specified, then a sudoku puzzle must be passed in through `stdin`, and a solved version of this puzzle (if a solution exists) will be printed.

## User Interface

`./sudoku create` or `./sudoku solve`

## Sudoku Pseudocode

## Breakdown of Functions

`main`

1. Parse and validate command line arguments
2. Determine which mode (`create` or `solve`) is desired
	1. If `create`, call `creator`
	2. If `solve`, load the puzzle passed through `stdin` into a `sudoku_t` structure and call `solve_puzzle`

`creator`


`solve_puzzle`

1. Find an unsolved element of the puzzle using `get_unsolved_element`
2. Attempt to place a number in this slot (starting at 1, increasing upwards)
	3. Check if the number is valid. If not, increment the number by 1
	4. If it is, valid, recursively call `solve_puzzle` to see if the puzzle is solved
	5. Return false if the puzzle cannot be solved.
6. If the puzzle is solved, return true.

## Major Data Structures

`sudoku`

Houses a 9x9 grid, initialized to all zeroes. Sudoku has the following functionality:

1. *sudoku_new*, which allocated memory and initializes an empty puzzle
2. *sudoku_edit*, which changes the value at a specified position
3. *sudoku_get*, which returns the value at a specified position
4. *sudoku_copy*, which duplicates a sudoku
5. *sudoku_load*, which loads a `sudoku_t` structure from a file
4. *sudoku_equal*, which checks is two puzzles match
5. *sudoku_print*, which prints the puzzle to `stdout`
6. *sudoku_delete*, which frees the memory that the sudoku occupies
7. *sudoku_isvalid*, which checks if the row, column, and box of a certain position are valid

## Exits

If `sudoku.c` fails, it will return with a nonzero exit code.

`sudoku.c` will exit for the following reasons:

1. Invalid number of command line arguments
2. Invalid specification of mode (`create` or `solve`)

Puzzles that are not able to be solved are handled internally, and will not output an error, but simply state that the puzzle cannot be solved. 

## Memory Leaks

Using `myvalgrind`, all memory leaks have been plugged.

## Testing

Testing information can be found in TESTING.md, and the test script can be found at `testing.sh`. This can be run by calling `make test`.

## Compilation

To compile, type `make` in the command line. To clean, use `make clean`.
