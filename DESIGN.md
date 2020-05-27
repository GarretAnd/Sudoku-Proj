There will be two major visible final products to the user in the ***Sudoku Project*** from `Sudoku.c`

1. Creating (called `Creator`) a random Sudoku Puzzle with one unique solution upon calling the script.
2. Solving (called `Solver`) this unique Sudoku Puzzle correctly.

The `Creator` will first initialize a `Sudoku` structure (more details on this structure below and in IMPLEMENTATION.md) to then randomly fill in with various random numbers, while making sure that the numbers it puts into the puzzle are valid. At the end of this process the puzzle will have one unique solution.

The `Solver` will read a `Sudoku` structure from a provided file and then go through the puzzle and solve it appropriately. It will go through each "hole" in the puzzle and based off the block it is in, the row, and the column that hole it is in it will determine the appropriate solution.

### User interface

The ***Sudoku Project*** reads from only the command line when in *create* mode, and reads from `stdin` to access the puzzle when in *solve* mode.

Create can be accessed as follows:

```
./sudoku create
```

Solve can be accessed as follows:

```
./sudoku solve
```

### Inputs and outputs

Inputs: a command line argument dictating *create* or *solve* will determine if input is needed from `stdin`; see the User Interface above.

Output of `Creator`: An initialized Sudoku Puzzle with a grid of 9x9 numbers varying from 0-9 where 0 represents the holes randomly scattered around the array with at least 40 holes in the array. This is either printed to stdout or to a file.

Output of `Solver`: A solved Sudoku Puzzle with a grid of 9x9 numbers varying from 1-9. This is either printed to stdout or to a file.

### Functional decomposition into modules

We anticipate the following modules or functions in the `Creator`:

 1. *main*, which parses arguments and initializes other modules.
 2. *number_inserter* which goes through the puzzle and randomly picks a number to insert in a random location.
 3. *is_valid* which makes sure the insertion of a specific number in a row/block/column is valid.
 4. *is_unique* which checks if there is a unique solution to the puzzle.

We anticipate the following modules or functions in the `Solver`:

 1. *main*, which parses arguments and initializes other modules.
 2. *sudoku_loader* which loads a 9x9 array that represents are Sudoku Puzzle into a data struct that will hold it.
 3. *sudoku_solver* which will go through the loaded puzzle and insert the right number at the "holes" that are open.
 4. *is_valid* which makes sure the insertion of a specific number in a row/block/column is valid.
 5. *game_won* which will check if there is a non-zero number at every spot in the array and tells us whether the game is over or not.

We anticipate the following modules or functions in the `common` directory to be shared by the `Solver` and `Creator`:

1. *sudoku_new* which creates a data structure that holds a 9x9 two-dimensional array
2. *sudoku_edit* which changes the value at a desired position
3. *sudoku_get* which returns the value at a certain position
4. *sudoku_print* which prints the puzzle to `stdout`
5. *sudoku_delete* which frees the memory of a puzzle
6. *is_valid* which checks if a row, column, and box are valid

### Pseudo code for logic/algorithmic flow

The `Creator` will run as follows:

1. Execute from a command line as shown in the User Interface.
2. Parse the command line, validate parameters, initialize other modules.
3. Make a variable of the `Sudoku_t` that will contain an empty 9x9 array called Puzzle.
4. Randomly go through the initial array and find a random spot.
  5. Pick a random number to insert at that slot
  6. Make sure the random number is a valid insertion in that row/column/box
    7. If it is not pick repeat steps 5 and 6.
    8. If it is insert the number at the slot.
    9. Remove this number from the known options of numbers to insert
    10. Repeat this process until there are no more numbers available to insert.
11. Call the solver function on the program and receive a solved Puzzle.
  12. Remove one element from the puzzle.
  13. Check if there is a unique solution.
    14. If there is, repeat steps 12 through 13.
    15. If there is not, undo the last delete you made.
16. Print this finished Puzzle to stdout or whatever file it is directed to.

The `Solver` will run as follows:
1. Find an empty block on the game board.
  2. If it can't find an empty block, the board is already finished.
  3. If it can find an empty block, Assign a valid value to said block.
    4. Recurse to next nonempty block and repeat steps 1-4.
    5. If recursion is not able to find a valid solution assign a different valid value to block.
      6. If all valid values are used up and a solution was not found.

### Dataflow through modules

 1. *main* parses parameters and passes them to the creator.
 2. *random* which initiates a random number generator and allows us to get random numbers.
 3. *creator* uses a `sudoku_t` structure to build, populate, and print a randomly generated puzzle.
 4. *libsudoku* does the building, editing, printing, deleting, and checking of sudoku puzzles.
 5. *solver* takes a sudoku puzzle as input, parses it into a `sudoku_t` structure, and solves it using edits, gets, and checks.

### Major Data Structures

The common directory provides the following data structure:

 1. *sudoku* which houses a 9x9 two-dimensional integer array

### Testing Plan

*Unit testing*.  A small test program in `testing.sh` to test each module to make sure it does what it's supposed to do.

*Integration testing*.  Assemble the solver and creator and test them as a whole using `testing.sh`.

For the creator, the following must be observed:

1. A random puzzle is generated with each call of `./sudoku create`
2. The puzzle is, in fact, solvable
3. The puzzle only has one solution

For the solver, the following must be observed:

1. The proposed solution outputted by `./sudoku solve` is correct

In addition, the following tests will be performed:

1. Provide a variety of incorrect command-line arguments to ensure proper parsing
2. Pass invalid puzzles to solver to ensure it imports puzzles properly

*Fuzz testing*. Fuzz testing will be performed in the `testing.sh` file. It will do the following:

1. Generate a variety (100) of random puzzles by calling `./sudoku create`
2. Attempt to solve these puzzles by calling `./sudoku solve`
3. If any puzzles are solved incorrectly, return an error
