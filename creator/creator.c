/* Author: Garret Andreine
 * Date: 5/26/2020
 * Purpose: CS50 Final project
 * All the functions needed to create a sudoku puzzle with a unique solution.
 */

#include "creator.h"
int rand_num (void){
  time_t t;

  // Intializes random number generator
  srand((unsigned) time(&t));

  // Gets initial random number than calls a modulus of 10
  // on this random to number to make sure the number is between 0-9
  return (int) (rand()%9); // returns random number of 0-9
}

sudoku_t *creator(void){  // Creates Sudoku puzzle with one unique solution
  sudoku_t *game = game_init();  // Makes game with random starting blocks

  if (game == NULL){  // If error upon creation of game just leaves creator
    return NULL;
  }

  bool solved = solve_puzzle(game);  // Solves the game

  if (!solved){  // Checks to make sure the game was properly solved.
    printf("Error. Game board not solved correctly... Leaving Solver.\n");
    return NULL;
  }

  make_unique(game);  // Makes the game have a unique solution

  return game; // Returns the finished game
}

void make_unique(sudoku_t *game){
  bool unique = true;
  int value;

  while (unique){  // While there is a unique solution
	  printf("getting random num\n");
    int x_coord = rand_num();  // Initalizes random coordinate values
    int y_coord = rand_num();
	printf("%d %d\n", x_coord, y_coord);
    value = sudoku_get(game, x_coord, y_coord);  // Gets value at edited space
    sudoku_edit(game, x_coord, y_coord, 0);  // 0s a random slot on the board
    unique = unique_solution(game);  // Checks if there is a unique solution
    if (!unique){   // When there isn't a unique solution
      sudoku_edit(game, x_coord, y_coord, value);
      // undo last edit to give it a unique solution back and stop editing
    }
  }
}


sudoku_t *game_init(void){
  sudoku_t *game = sudoku_new();  // Gets sudoku data type

  if (game == NULL){  // Checks to make sure Sudoku game was corrected
    printf("Error. Game board not created correctly... Leaving Solver.\n");
    return NULL;
  }

  int value;
  int i = 1; // Makes array of first round of numbers to insert

  while (i < 10){  // Goes through whole array

    int x_coord = (int)rand_num();  // Initalizes random coordinate values
    int y_coord = (int)rand_num();

    value = sudoku_get(game, x_coord, y_coord);  // Gets value at random tile

    if (value == 0){ // If there is nothing at that tile
      // Sets a random tile in the game with the values 1-9
      sudoku_edit(game, x_coord, y_coord, i);
    }  // Don't need to worry about valid insertion yet because no duplicate #s
    else {
      i--;  // Goes down a value to try again for the number it is on if needed
    }

    i++;
  }

  return game;  // returns initalized random game
}
