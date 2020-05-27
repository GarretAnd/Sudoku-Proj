#include "solver.h"
#include <stdlib.h>
#include "random.h"

static void get_unsolved_element(sudoku_t *sudoku, int *row, int *col);
static bool solve_puzzle_backwards(sudoku_t *sudoku);

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

bool solve_puzzle_random(sudoku_t *sudoku){
	int row = -1;
        int col = -1;
        get_unsolved_element(sudoku, &row, &col);
        if(row == -1 && col == -1) return true;
	int i = rand_num()+1;
        for(int j = 0; j < 9; j++){
                sudoku_edit(sudoku, row, col, i);
                if(sudoku_isvalid(sudoku, row, col) && solve_puzzle_random(sudoku)) return true;
		i++;
		if(i == 10) i = 1;
        }
        sudoku_edit(sudoku, row, col, 0);
        return false;
}

bool unique_solution(sudoku_t *sudoku){
	sudoku_t *copy1 = sudoku_copy(sudoku);
	sudoku_t *copy2 = sudoku_copy(sudoku);
	if (!solve_puzzle(copy1)) return false;
	solve_puzzle_backwards(copy2);
	bool match = sudoku_equal(copy1, copy2);
	sudoku_delete(copy1);
	sudoku_delete(copy2);
	return match;
}

static bool solve_puzzle_backwards(sudoku_t *sudoku){
        int row = -1;
        int col = -1;
        get_unsolved_element(sudoku, &row, &col);
        if(row == -1 && col == -1) return true;

        for(int i = 9; i >= 1; i--){
                sudoku_edit(sudoku, row, col, i);
                if(sudoku_isvalid(sudoku, row, col) && solve_puzzle_backwards(sudoku)) return true;
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
