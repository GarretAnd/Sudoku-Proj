/* Author: Garret Andreine
 * Date: 5/26/2020
 * Purpose: CS50 Final project
 * All the functions needed to create a sudoku puzzle with a unique solution.
 */

#include "creator.h"
#include "random.h"

sudoku_t *creator(void){  // Creates Sudoku puzzle with one unique solution
  sudoku_t *game = game_init();  // Makes game with random starting blocks
  gen_init();  // Initializes random number generator

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
