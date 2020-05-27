/* Authors: cs50maybemajors
 * Date: 5/27/2020
 * Purpose: CS50 Final project
 * sudoku.c parses arguments and calls the proper functions from other modules
 */

#include "solver.h"
#include "libsudoku.h"
#include "creator.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(const int argc, char *argv[]){
	// check number of arguments
	if (argc != 2){
		fprintf(stderr, "Usage: must specify function\n");
		return 1;
	}

	// determine which mode is desired
	if (strcmp(argv[1], "create") == 0){ // if create, create a puzzle
		sudoku_t *sudoku = creator();
		if (sudoku == NULL){
			fprintf(stderr, "Error: failed to create sudoku puzzle\n");
                	return 3;
		}
		sudoku_print(sudoku);
		sudoku_delete(sudoku);
	} else if (strcmp(argv[1], "solve") == 0){ // if solve, solve a puzzle from stdin
		sudoku_t *sudoku = sudoku_load(stdin);
		if (!solve_puzzle(sudoku)){
			fprintf(stderr, "Error: given sudoku puzzle could not be solved\n");
                        return 4;
		}
		sudoku_print(sudoku);
		sudoku_delete(sudoku);
	} else{ // if not create or solve, return error
		fprintf(stderr, "Error: must specify valid function\n");
                return 2;
	}
	return 0;
}
