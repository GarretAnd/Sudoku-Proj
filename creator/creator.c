/* Author: Garret Andreine
 * Date: 5/26/2020
 * Purpose: CS50 Final project
 * All the functions needed to create a sudoku puzzle with a unique solution.
 */

#include "creator.h"

sudoku_t *creator(void){  // Creates Sudoku puzzle with one unique solution
  gen_init();  // Initializes random number generator
  sudoku_t *game = game_init();  // Makes game with random starting blocks

  if (game == NULL){  // If error upon creation of game just leaves creator
    return NULL;
  }
  make_unique(game);  // Makes the game have a unique solution

  return game; // Returns the finished game
}

void make_unique(sudoku_t *game){
  bool unique = true;
  int value;

  while (unique){  // While there is a unique solution
    int x_coord = rand_num();  // Initalizes random coordinate values
    int y_coord = rand_num();
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
  solve_puzzle_random(game);  // Solves the game and removes random spots
  return game;
}

#ifdef TESTMODE

#include "creator.h"
#include <unistd.h>  // Includes needed libraries

int main(void){  // unit test

  sudoku_t *puzzle_0 = creator(); // Creates Sudoku Puzzles and sleeps for variance in seed
  sleep(1);
  sudoku_t *puzzle_1 = creator();
  sleep(1);
  sudoku_t *puzzle_2 = creator();
  sleep(1);
  sudoku_t *puzzle_3 = creator();
  sleep(1);
  sudoku_t *puzzle_4 = creator();
  sleep(1);
  sudoku_t *puzzle_5 = creator();
  sleep(1);
  sudoku_t *puzzle_6 = creator();
  sleep(1);
  sudoku_t *puzzle_7 = creator();
  sleep(1);
  sudoku_t *puzzle_8 = creator();
  sleep(1);
  sudoku_t *puzzle_9 = creator();
  sleep(1);

  if (puzzle_0 == NULL  || puzzle_1 == NULL || puzzle_2 == NULL  // Makes sure puzzles exist
      || puzzle_3 == NULL || puzzle_4 == NULL  || puzzle_5 == NULL || puzzle_6 == NULL
       || puzzle_6 == NULL || puzzle_7 == NULL  || puzzle_8 == NULL || puzzle_9 == NULL){
    printf("Error. Puzzle Gen failure.\n");
    return 1;
  }

  sudoku_t *array[] = {puzzle_0, puzzle_1, puzzle_2, puzzle_3, puzzle_4, puzzle_5, puzzle_6,
                        puzzle_7, puzzle_8, puzzle_9};

  int x = 0;
  int y = 0;
  int z = 0;

  while (z < 10){  // loops through array
    while (x < 9){  // loops through every position ion board
      while(y < 9){
          sudoku_t *result = array[z];
          bool result_0 = sudoku_isvalid(result, x, y);  // checks if puzzles are valid
          if (!result_0){
            printf("Error. Found invalid puzzles.\n");
            return 1;
          }
        y++;
      }
      x++;
    }
    z++;
  }

  x = 0;
  y = 1;

  while (x < 10){  // loops through array values to compare them
    while(y < 10){
      bool result_2 = sudoku_equal(array[x], array[y]);  // checks if puzzles are equal
      if (result_2){
        printf("Error. Found equal puzzles. \n");
        printf("The equal puzzles are %d and %d\n", x, y);
        return 1;
      }
      y++;
    }
    x++;
    y = x + 1;
  }

  sudoku_delete(puzzle_0);  // frees all puzzles
  sudoku_delete(puzzle_1);
  sudoku_delete(puzzle_2);
  sudoku_delete(puzzle_3);
  sudoku_delete(puzzle_4);
  sudoku_delete(puzzle_5);
  sudoku_delete(puzzle_6);
  sudoku_delete(puzzle_7);
  sudoku_delete(puzzle_8);
  sudoku_delete(puzzle_9);

  printf("\n***Creator Unit Test Passed***\n\n");
  return 0;
}

#endif
