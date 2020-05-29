# CS50 Final Project
## CS50 Spring 2020
### By Garret Andreine

### Creator

The creator directory stores `creator.c`, which houses functions that are responsible for creating sudoku puzzles with unique solutions.

`creator` can perform the following tasks:

1. Initialize a random number generator, which can be used to populate the puzzle.
2. Initialize an empty sudoku puzzle.
3. Add random numbers in random spots of a sudoku puzzle.
4. Edit a puzzle to ensure it has one unique solution.
5. Create a puzzle from scratch (combining the above four).

### Usage

`creator.c` is meant to be called by outside modules, and thus does not have an executable. However, it does have a unit test that can be called with the command `make test` while in the `creator` directory.

`creator` has the following functionality:

```c
/******************game_init********************
* Creates a Sudoku game with 9 random blocks filled in
*
* Returns:
*   sudoku_t * containing game board*/
sudoku_t *game_init(void);

/******************make_unique********************
* Creates a Sudoku game with 9 random blocks filled in
*
* Returns:
*  void */
void make_unique(sudoku_t *game);

/******************creator********************
* Creates a Sudoku game with a unique solution
*
* Returns:
*  sudoku_t * containing game board with a unique solution */
sudoku_t *creator(void);
```

### Assumptions

No assumptions were made beyond those that were clear from the spec.

### Compilation

To compile, call `make`. To clean, call `make clean`.
