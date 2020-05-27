---
layout: page
title: Sudoku Final Project Design Spec
---

There will be two major visible final products to the user in the ***Sudoku Project*** from `Sudoku.c`

1. Creating (called `Creator`) a random Sudoku Puzzle with one unique solution upon calling the script.
2. Solving (called `Solver`) this unique Sudoku Puzzle correctly.

The `Creator` will first initialize a `Sudoku` structure (more details on this structure below and in IMPLEMENTATION.md) to then randomly fill in with various random numbers, while making sure that the numbers it puts into the puzzle are valid. At the end of this process the puzzle will have one unique solution.

The `Solver` will read a `Sudoku` structure from a provided file and then go through the puzzle and solve it appropriately. It will go through each "hole" in the puzzle and based off the block it is in, the row, and the column that hole it is in it will determine the appropriate solution.

A Design Spec should contain several sections:

* User interface
* Inputs and Outputs
* Functional decomposition into modules
* Pseudo code for logic/algorithmic flow
* Dataflow through modules
* Major data structures
* Testing plan

Let's look through each.

### User interface

The ***Sudoku Project*** only interface with the user is on the command-line.

```
./sudoku create
```

```
./sudoku solver
```

### Inputs and outputs

Inputs: the only inputs are command-line parameters; see the User Interface above.

Output of `Creator`: An initialized Sudoku Puzzle with a grid of 9x9 numbers varying from 0-9 where 0 represents the holes randomly scattered around the array with at least 40 holes in the array. This is either printed to stdout or to a file.

Output of `Solver`: A solved Sudoku Puzzle with a grid of 9x9 numbers varying from 1-9. This is either printed to stdout or to a file.

### Functional decomposition into modules

We anticipate the following modules or functions in the `Creator`:

 1. *main*, which parses arguments and initializes other modules.
 2. *sudoku_maker* which creates a data struct that holds an initialized 9x9 array which is the Sudoku Puzzle.
 3. *number_inserter* which goes through the puzzle and randomly picks a number to insert in a random location.
 4. *is_valid* which makes sure the insertion of a specific number in a row/block/column is valid.
 5. *is_unique* which checks if there is a unique solution to the puzzle. 
 6. *sudoku_print* which prints the puzzle to stdin or any specified file.

We anticipate the following modules or functions in the `Solver`:

 1. *main*, which parses arguments and initializes other modules.
 2. *sudoku_loader* which loads a 9x9 array that represents are Sudoku Puzzle into a data struct that will hold it.
 3. *sudoku_solver* which will go through the loaded puzzle and insert the right number at the "holes" that are open.
 4. *is_valid* which makes sure the insertion of a specific number in a row/block/column is valid.
 5. *game_won* which will check if there is a non-zero number at every spot in the array and tells us whether the game is over or not.
 5. *sudoku_print* which prints the puzzle to stdin or any specified file.

And some helper modules that provide data structures:

 1. *Sudoku* a struct that holds a 9x9 multidimensional array which is our puzzle
 2. *set* which will hold the values in the row/column/box for validation.

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
    14. If there is stop inserting numbers.
    15. If there is not, repeat steps 12 through 13.
16. Print this finished Puzzle to stdout or whatever file it is directed to.

The `Solver` will run as follows:  TALK TO LUC TOMORROW ABOUT HOW DAFUQ HE IS GONNA DO THIS SHIT

### Dataflow through modules

 1. *main* parses parameters and passes them to the crawler.
 2. *crawler* uses a bag to track pages to explore, and hashtable to track pages seen; when it explores a page it gives the page URL to the pagefetcher, then the result to pagesaver, then to the pagescanner.
 3. *pagefetcher* fetches the contents (HTML) for a page from a URL and returns.
 4. *pagesaver* outputs a page to the appropriate file.
 4. *pagescanner* extracts URLs from a page and returns one at a time.

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
