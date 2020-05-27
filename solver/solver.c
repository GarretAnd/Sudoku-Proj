#include "solver.h"
#include <stdlib.h>

static void get_unsolved_element(sudoku_t *sudoku, int *row, int *col);

bool solve_puzzle(sudoku_t *sudoku){
	int row = -1;
	int col = -1;
	get_unsolved_element(sudoku, &row, &col);
	if(row == -1 && col == -1) return true;
	
	for(int i = 1; i <= 9; i++){
		sudoku_edit(sudoku, row, col, i);
		if(sudoku_isvalid(sudoku, row, col) && solve_puzzle(sudoku)) return true;
	}
	sudoku_edit(sudoku, row, col, 0);
	return false;
}

static void get_unsolved_element(sudoku_t *sudoku, int *row, int *col){
        for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                        if(sudoku_get(sudoku, i, j) == 0){
                                *row = i;
                                *col = j;
                                break;
                        }
                }
                if(*row == -1 && *col == -1)break;
        }
}
