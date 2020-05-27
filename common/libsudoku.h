/* Author: Quinn Spraut
 * Date: 5/26/2020
 * Purpose: CS50 Final project
 * Header file for libsudoku.c
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
/******************struct************************
 * sudoku_t stores a SIZExSIZE grid
 */
typedef struct sudoku sudoku_t;

/******************functions*********************
 * ****************sudoku_new********************
 * Allocates memory for a sudoku_t struct
 * Populates the grid with 0's
 * Returns:
 * 	sudoku_t struct if successful
 * 	NULL if failure
 * Caller is responsible for later free'ing the 
 * sudoku by calling sudoku_delete
 */
sudoku_t *sudoku_new();

/******************sudoku_edit*******************
 * Sets sudoku[i][j] to value
 * Does nothing if sudoku is NULL, i,j<0, i,j>8,
 * value<1, or value>9
 */
void sudoku_edit(sudoku_t *sudoku, int i, int j, int value);

/******************sudoku_print******************
 * Prints the sudoku grid, one row per line
 * Prints nothing if sudoku is NULL
 */
void sudoku_print(sudoku_t *sudoku);

/******************sudoku_delete*****************
 * Frees the memory occupied by the sudoku
 * Does nothing if sudoku is NULL
 */
void sudoku_delete(sudoku_t *sudoku);

/******************sudoku_rowcheck***************
 * Checks for duplicate numbers in the i'th row
 * Returns:
 * 	false if sudoku is NULL, or i<0 or i>8
 * 	false if there is a duplicate number in the row
 * 	true if no duplicate numbers in the row
 */
bool sudoku_rowcheck(sudoku_t *sudoku, int i);

/******************sudoku_columncheck************
 * Checks for duplicate numbers in the j'th column
 * Returns:
 * 	false if sudoku is NULL, or j<0 or j>8
 * 	false if there is a duplicate number in the column
 * 	true if no duplicate numbers in the column
 */
bool sudoku_columncheck(sudoku_t *sudoku, int j);

/******************sudoku_boxcheck***************
 * Checks for duplicate numbers in the box that contains i,j
 * Returns:
 * 	false if sudoku is NULL, or i,j<0 or i,j>8
 * 	false if there is a duplicate number in the box
 * 	true if no duplicate numbers in the box
 */
bool sudoku_boxcheck(sudoku_t *sudoku, int i, int j);
