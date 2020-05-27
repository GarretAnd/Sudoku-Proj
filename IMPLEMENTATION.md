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

## Exits

If `sudoku.c` fails, it will return with a nonzero exit code.

`sudoku.c` will exit for the following reasons:


All other errors occur within each query obtained from `stdin`, and so instead of exiting a new query is requested.

## Memory Leaks

Using `myvalgrind`, all memory leaks have been plugged.

## Testing

Testing information can be found in TESTING.md, and the test script can be found at `testing.sh`. This can be run by calling `make test`.

## Compilation

To compile, type `make` in the command line. To clean, use `make clean`.