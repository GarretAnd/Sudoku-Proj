# CS50 Final Project
## CS50 Spring 2020

### creator

The creator directory stores `creator.c`, which is responsible for building sudoku puzzles.

`creator` can perform the following tasks:

1. Generate random numbers, which can be used to populate the puzzle
2. Initalize an empty sudoku puzzle
3. Add random numbers in random spots of a sudoku puzzle
4. Edit a puzzle to ensure it has one unique solution
5. Create a puzzle from scratch (combining the above four)

### Usage

`creator.c` is meant to be called by outside modules, and thus does not have an exectuable.

### Assumptions

No assumptions were made beyond those that were clear from the spec.

### Compilation

To compile, call `make`. To clean, call `make clean`.
