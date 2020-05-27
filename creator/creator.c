/* Author: Garret Andreine
 * Date: 5/26/2020
 * Purpose: CS50 Final project
 * All the functions needed to create a sudoku puzzle.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libsudoku.h"
#include 

int rand_num (void){
  int x;
  time_t t;

  // Intializes random number generator
  srand((unsigned) time(&t));

  // Gets initial random number than calls a modulus of 10
  // on this random to number to make sure the number is between 0-9
  x = rand();
  x = x % 10;

  return(x);  // returns random number of 0-9
}

void creator(void){  // Creates Sudoku puzzle with one unique solution

  sudoku_t *game = sudoku_new();  // Gets sudoku data type

  if (game == NULL){  // Checks to make sure Sudoku game was corrected
    printf("Error. Game board not created correctly... Leaving Solver.\n");
    return;
  }

  int i = 0; // Makes array of first round of numbers to insert
  int value;
  int init_array[9] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];

  while (i < 10){

    int x_coord = rand_num();  // Initalizes random coordinate values
    int y_coord = rand_num();

    value = sudoku_get(game, x_coord, y_coord);  // Gets value at random tile

    if (value == 0){ // If there is nothing at that tile
      // Sets a random tile in the game with the values 0-9
      sudoku_edit(game, x_coord, y_coord, init_array[i]);
    }  // Don't need to worry about valid insertion yet because no duplicate #s
    else {
      i--;  // Goes down a value to try again for the number it is on if needed
    }

    i++;
  }



}
