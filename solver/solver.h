#ifndef __SOLVER_H
#define __SOLVER_H

#include <stdbool.h>
#include "libsudoku.h"

/*
 * finds a solution for given sudoku and puts solution into said sudoku
 * returns true if a solution was found, false otherwise
 */
bool solve_puzzle(sudoku_t *sudoku);

/*
 * returns true if the given sudoku has exactly one valid solution, false otherwise
 * Note: does not solve given sudoku, just checks for solutions.
 */
bool unique_solution(sudoku_t *sudoku);

bool solve_puzzle_random(sudoku_t *sudoku);

#endif // __SOLVER_H
