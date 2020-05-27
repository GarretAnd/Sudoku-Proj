/* Author: Quinn Spraut
 * Date: 5/26/2020
 * Purpose: CS50 Final project
 * libsudoku is the c file shared between creator and solver
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 9

typedef struct sudoku{
	int grid[SIZE][SIZE];
} sudoku_t;

sudoku_t *sudoku_new()
{
	sudoku_t *sudoku = malloc(sizeof(sudoku_t));
	
	// check if successful
	if (sudoku == NULL){
		fprintf(stderr, "Error: Could not allocate memory for sudoku\n");
		return NULL;
	}

	// populate with 0
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			sudoku->grid[i][j] = 0;
		}
	}

	return sudoku;
}

void sudoku_edit(sudoku_t *sudoku, int i, int j, int value){
	if (sudoku == NULL || i < 0 || j < 0 || value < 1 || i > 8 || j > 8 || value > 9){
		fprintf(stderr, "Error: could not edit sudoku\n");
		return;
	}

	sudoku->grid[i][j] = value;
}

void sudoku_print(sudoku_t *sudoku)
{
	if (sudoku == NULL){
		fprintf(stderr, "Error: could not access sudoku\n");
		return;
	}
	for (int i = 0; i < SIZE; i++){ // iterate through column
		for (int j = 0; j < SIZE; j++){ // iterate through row
			fprintf(stdout, "%d  ", sudoku->grid[i][j]);
		}
		fprintf(stdout, "\n");
	}
}

void sudoku_delete(sudoku_t *sudoku)
{
	if (sudoku != NULL){
		free(sudoku);
		sudoku = NULL;
	}
}

bool sudoku_rowcheck(sudoku_t *sudoku, int i)
{
	if (sudoku == NULL || i < 0 || i > 8){
		fprintf(stderr, "Error: could not check row\n");
		return false;
	}
	
	// create array to store what values have been seen
	int array[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (int j = 0; j < SIZE; j++){
		int slot = sudoku->grid[i][j] - 1;
		
		if (slot < 0){ // ignore 0's in the grid
			continue;
		}
		
		if (array[slot] == 1){ // if this number has been seen before, return false
			return false;
		} else { // else, mark that the number has been seen
			array[slot] = 1;
		}
	}
	return true;
}

bool sudoku_columncheck(sudoku_t *sudoku, int j)
{
	if (sudoku == NULL || j < 0 || j > 8){
		fprintf(stderr, "Error: could not check column\n");
		return false;
	}
	
	// create array to store what values have been seen
	int array[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (int i = 0; i < SIZE; i++){
		int slot = sudoku->grid[i][j] - 1;
		
		if (slot < 0){ // ignore 0's in the grid
			continue;
		}
		
		if (array[slot] == 1){ // if this number has been seen before, return false
			return false;
		} else { // else, mark that the number has been seen
			array[slot] = 1;
		}
	}
	return true;
}

bool sudoku_boxcheck(sudoku_t *sudoku, int i, int j)
{
	if (sudoku == NULL || i < 0 || j < 0 || i > 8 || j > 8){
		fprintf(stderr, "Error: could not check box\n");
		return false;
	}
	
	// determine which box we are in
	int box_i;
	int box_j;
	if (i < 3){
		box_i = 0;
	} else if (i < 6) {
		box_i = 3;
	} else {
		box_i = 6;
	}

	if (j < 3){
		box_j = 0;
	} else if (j < 6) {
		box_j = 3;
	} else {
		box_j = 6;
	}
	
	// check for duplicate numbers in the box
	int array[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int ci = box_i; ci < box_i + 3; ci++){
		for (int cj = box_j; cj < box_j + 3; cj++){
			int slot = sudoku->grid[ci][cj] - 1;
			if (slot < 0){ // ignore 0's in the grid
				continue;
			}
		
			if (array[slot] == 1){ // if this number has been seen before, return false
				return false;
			} else { // else, mark that the number has been seen
				array[slot] = 1;
			}
		}
	}
	return true;
}
