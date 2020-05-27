/* Author: Garret Andreine
 * Date: 5/26/2020
 * Purpose: CS50 Final project
 * Header file for creator.c
 */
#ifndef __CREATOR_H
#define __CREATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>
#include <time.h>
#include "solver.h"
#include "libsudoku.h"  // Includes Needed Libraries

/*******************functions**********************/

/******************rand_num********************
* Creates random integer of 0-9
*
* Returns:
*   int with random value */
int rand_num (void); // Gets a random number 1 through 10

/******************gen_init********************
* Initializes random number generator based off a seed of the time
*
* Returns:
*   void */
void gen_init(void);

/******************game_init********************
* Creates a Sudoku game with 9 random blocks filled in
*
* Makes the sudoku_t type
* Goes through and puts the values 1-9 into the board at random slots
*
* Returns:
*   sudoku_t * containing game board */
sudoku_t *game_init(void);

/******************make_unique********************
* Creates a Sudoku game with 9 random blocks filled in
*
* Gets the value of a random slot on the board
* Puts a hole at that slot
* Checks if the game still has a unique unique_solution
* Continues this process until the game is no longer unique
* Undoes the delete that made the game no longer unique
*
* Returns:
*  void */
void make_unique(sudoku_t *game);

/******************make_unique********************
* Creates a Sudoku game with a unique solution
*
* Makes a sudoku game board
* Solves the game board
* Makes the game board have a unique solution
*
* Returns:
*  sudoku_t * containing game board with a unique solution */
sudoku_t *creator(void);

#endif // __CREATOR_H
