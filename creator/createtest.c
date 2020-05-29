#ifdef TESTMODE

#include "creator.h"
#include <unistd.h>  // Includes needed libraries

int main(void){

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

  if (puzzle_0 == NULL  || puzzle_1 == NULL || puzzle_2 == NULL  // Makes sure puzzles exist
      || puzzle_3 == NULL || puzzle_4 == NULL  || puzzle_5 == NULL || puzzle_6 == NULL
       || puzzle_6 == NULL || puzzle_7 == NULL  || puzzle_8 == NULL || puzzle_9 == NULL){
    printf("Error. Puzzle Gen failure.\n");
    return 1;
  }

  sudoku_t **array = {puzzle_0, puzzle_1, puzzle_2, puzzle_3, puzzle_4, puzzle_5, puzzle_6
                        puzzle_7, puzzle_8, puzzle_9};

  int x = 0;
  int y = 0;
  int z = 0;

  while (z < 10){  // loops through array
    while (x < 9){  // loops through every position ion board
      while(y < 9){
          sudoku_t *result = array[z];
          bool result = sudoku_isvalid(result, x, y);  // checks if puzzles are valid
          if (!result){
            printf("Error. Found invalid puzzles. \n");
            return 1;
          }
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
      if (!result_2){
        printf("Error. Found equal puzzles. \n");
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

  return 0;
}

#endif
