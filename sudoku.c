#include "solver.h"
#include "libsudoku.h"
#include "creator.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(const int argc, char *argv[]){
	if (argc != 2){
		fprintf(stderr, "usage: must specify function");
		return 1;
	}
	if (strcmp(argv[1], "make") == 0){
		sudokut_t *sudoku = creator();
		sudoku_print(sudoku);
	} else if (strcmp(argv[1], "solve") == 0){
		sudokut_t *sudoku = sudoku_load(stdin);
		solve_puzzle(sudoku);
		sudoku_print(sudoku);
	} else{
		fprintf(stderr, "error: must specify valid function");
                return 2;
	}
	return 0;
}
