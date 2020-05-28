/* Author: cs50maybemajors
 * Date: 5/26/2020
 * Purpose: CS50 Final Project solution
 * Tests the libsudoku functions
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "libsudoku.h"

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
