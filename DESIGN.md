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

### Major data structures

Three helper modules provide data structures:

 1. *bag* of page (URL, depth) structures
 2. *set* of URLs (indirectly used by hashtable)
 4. *hashtable* of URLs

### Testing plan

*Unit testing*.  A small test program in `testing.sh` to test each module to make sure it does what it's supposed to do.

*Integration testing*.  Assemble the crawler and test it as a whole using `testing.sh`.
In each case, examine the output files carefully to be sure they have the contents of the correct page, with the correct URL, and the correct depth.
Ensure that no pages are missing or duplicated.
Print "progress" indicators from the crawler as it proceeds (e.g., print each URL explored, and each URL found in the pages it explores) so you can watch its progress as it runs.

0. Test the program with various forms of incorrect command-line arguments to ensure that its command-line parsing, and validation of those parameters, works correctly.

0. Test the crawler with a `seedURL` that points to a non-existent server.

0. Test the crawler with a `seedURL` that points to a non-internal server.

0. Test the crawler with a `seedURL` that points to a valid server but non-existent page.

1. Crawl a simple, closed set of cross-linked web pages to crawl.
Ensure that some page(s) are mentioned multiple times within a page, and multiple times across the set of pages.
Ensure there is a loop (a cycle in the graph of pages).
In such a little site, you know exactly what set of pages should be crawled, at what depths, and you know where your program might trip up.

2. Point the crawler at a page in that site, and explore at depths 0, 1, 2, 3, 4, 5.
Verify that the files created match expectations.

2. Repeat with a different seed page in that same site.
If the site is indeed a graph, with cycles, there should be several interesting starting points.

3. Point the crawler at our Wikipedia playground.
Explore at depths 0, 1, 2.
(It takes a long time to run at depth 2 or higher!) Verify that the files created match expectations.

5. When you are confident that your crawler runs well, test it on a part of our playground or with a greater depth - but be ready to kill it if it seems to be running amok.
