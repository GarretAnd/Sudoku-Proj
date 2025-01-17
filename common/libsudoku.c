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

void sudoku_edit(sudoku_t *sudoku, int i, int j, int value)
{
	if (sudoku == NULL || i < 0 || j < 0 || value < 0 || i > 8 || j > 8 || value > 9){
		fprintf(stderr, "Error: could not edit sudoku\n");
		return;
	}

	sudoku->grid[i][j] = value;
}

int sudoku_get(sudoku_t *sudoku, int i, int j)
{
	if (sudoku == NULL || i < 0 || j < 0 || i > 8 || j > 8){
		fprintf(stderr, "Error: could not access requested value\n");
		return -1;
	}
	return sudoku->grid[i][j];
}

void sudoku_print(sudoku_t *sudoku)
{
	if (sudoku == NULL){
		fprintf(stderr, "Error: could not access sudoku\n");
		return;
	}
	for (int i = 0; i < SIZE; i++){ // iterate through row
		for (int j = 0; j < SIZE; j++){ // iterate through column
			fprintf(stdout, "%d  ", sudoku->grid[i][j]);
		}
		fprintf(stdout, "\n");
	}
}

sudoku_t *sudoku_load(FILE *fp){
	if (fp == NULL) return NULL;
	sudoku_t *sudoku = sudoku_new();
	if (sudoku == NULL) return NULL;
	int col = 0;
	int row = 0;
	int value;
	while (fscanf(fp, "%d ", &value) != -1){
		sudoku->grid[row][col] = value;
		col++;
		if (col >= 9){
			col = 0;
			row++;
		}
	}
	return sudoku;
}

sudoku_t *sudoku_copy(sudoku_t *sudoku){
	if (sudoku == NULL){
		fprintf(stderr, "Error: could not access sudoku\n");
		return NULL;
	}

	sudoku_t *copy = sudoku_new();
	if (copy == NULL){ // check if memory was allocated
		fprintf(stderr, "Error: could not allocate memory for copy\n");
		return NULL;
	}

	for(int i = 0; i < 9; i++){ // iterate through rows
		for(int j = 0; j < 9; j++){ // iterate through columns
			copy->grid[i][j] = sudoku->grid[i][j]; // copy values
		}
	}
	return copy;
}

bool sudoku_equal(sudoku_t *sudoku1, sudoku_t *sudoku2){
	if (sudoku1 == NULL || sudoku2 == NULL) return false; //protect from null givens
	for(int i = 0; i < 9; i++){ // iterate through rows
                for(int j = 0; j < 9; j++){ // iterate through columns
			if (sudoku1->grid[i][j] != sudoku2->grid[i][j]) return false; //elements aren't equal
		}
	}
	return true;
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

bool sudoku_isvalid(sudoku_t *sudoku, int i, int j)
{
	// check row, column, and box of i,j
	// each function checks sudoku, i, and j internally
	if (sudoku_rowcheck(sudoku, i)){
		if (sudoku_columncheck(sudoku, j)){
			if (sudoku_boxcheck(sudoku, i, j)){
				return true;
			}
		}
	}
	return false;
}

#ifdef TESTMODE
int main()
{
	fprintf(stdout, "Creating sudoku:\n");
	sudoku_t *sudoku = sudoku_new();
	if (sudoku == NULL){
		fprintf(stderr, "Error: failed to create sudoku\n");
		return 1;
	}

	fprintf(stdout, "Creating valid row, column, and box:\n");
	sudoku_edit(sudoku, 0, 0, 1);
	sudoku_edit(sudoku, 0, 1, 2);
	sudoku_edit(sudoku, 0, 2, 3);
	sudoku_edit(sudoku, 1, 0, 4);
	sudoku_edit(sudoku, 1, 1, 5);
	sudoku_edit(sudoku, 1, 2, 6);
	sudoku_edit(sudoku, 2, 0, 7);
	sudoku_edit(sudoku, 2, 1, 8);
	sudoku_edit(sudoku, 2, 2, 9);
	sudoku_print(sudoku);
	
	fprintf(stdout, "\nChecking row/column/box testers on 0, 0:\n");
	if (sudoku_rowcheck(sudoku, 0)){
		fprintf(stdout, "Passed row check\n");
	} else {
		fprintf(stdout, "Failed row check\n");
	}
	if (sudoku_columncheck(sudoku, 0)){
		fprintf(stdout, "Passed column check\n");
	} else {
		fprintf(stdout, "Failed column check\n");
	}
	if (sudoku_boxcheck(sudoku, 0, 0)){
		fprintf(stdout, "Passed box check\n");
	} else {
		fprintf(stdout, "Failed box check\n");
	}
	if (sudoku_isvalid(sudoku, 0, 0)){
		fprintf(stdout, "Passed isvalid check\n");
	} else {
		fprintf(stdout, "Failed isvalid check\n");
	}

	fprintf(stdout, "Testing the get function, value at 1,1: %d\n", sudoku_get(sudoku, 1, 1));

	fprintf(stdout, "Creating invalid row/column/box:\n");
	sudoku_edit(sudoku, 6, 6, 1);
	sudoku_edit(sudoku, 6, 7, 2);
	sudoku_edit(sudoku, 6, 8, 2);
	sudoku_edit(sudoku, 7, 6, 1);
	sudoku_edit(sudoku, 7, 7, 1);
	sudoku_edit(sudoku, 7, 8, 1);
	sudoku_edit(sudoku, 8, 6, 3);
	sudoku_edit(sudoku, 8, 7, 2);
	sudoku_edit(sudoku, 8, 8, 3);
	sudoku_print(sudoku);

	fprintf(stdout, "\nChecking row/column/box testers on 6, 7:\n");
	if (sudoku_rowcheck(sudoku, 6)){
		fprintf(stdout, "Passed row check\n");
	} else {
		fprintf(stdout, "Failed row check\n");
	}
	if (sudoku_columncheck(sudoku, 7)){
		fprintf(stdout, "Passed column check\n");
	} else {
		fprintf(stdout, "Failed column check\n");
	}
	if (sudoku_boxcheck(sudoku, 6, 7)){
		fprintf(stdout, "Passed box check\n");
	} else {
		fprintf(stdout, "Failed box check\n");
	}
	if (sudoku_isvalid(sudoku, 6, 7)){
		fprintf(stdout, "Passed isvalid check\n");
	} else {
		fprintf(stdout, "Failed isvalid check\n");
	}
	
	fprintf(stdout, "Testing copy:\n");
	sudoku_t *copy = sudoku_copy(sudoku);
	sudoku_print(copy);

	fprintf(stdout, "Testing equals:\n");

	if (sudoku_equal(sudoku, copy)){
		fprintf(stdout, "The sudoku equals its copy\n");
	} else {
		fprintf(stdout, "The sudoku does not equal its copy\n");
	}

	fprintf(stdout, "\nDeleting sudoku\n");
	sudoku_delete(sudoku);
	sudoku_delete(copy);

	return 0;
}
#endif
