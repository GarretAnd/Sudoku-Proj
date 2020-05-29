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
                if(*row != -1 && *col != -1)break;
        }
}
#ifdef TESTMODE
int main(void){
        sudoku_t *unsolvable = sudoku_new();
        sudoku_edit(unsolvable, 0, 0, 1);
        sudoku_edit(unsolvable, 2, 2, 1);
        sudoku_t *solvable = sudoku_new();
        sudoku_edit(solvable, 0, 0, 1);
        sudoku_edit(solvable, 2, 2, 3);
        sudoku_edit(solvable, 4, 7, 6);
        sudoku_t *solvable2 = sudoku_copy(solvable);
        sudoku_t *blank = sudoku_new();
        printf("testing solve_puzzle with unsolvable puzzle...\n");
        if (solve_puzzle(unsolvable)){
                fprintf(stderr, "unsolvable puzzle test failed\n");
                return 1;
        }
        printf("passed!\n");
        printf("testing solve_puzzle with solvable puzzle...\n");
        printf("solving: \n");
        sudoku_print(solvable);
        if (!solve_puzzle(solvable)){
                fprintf(stderr, "solvable puzzle test failed\n");
                return 1;
        }
        printf("solution:\n");
        sudoku_print(solvable);
        for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                        if (!sudoku_isvalid(solvable, i, j)){
                                fprintf(stderr, "solvable puzzle test failed\n");
                                return 1;
                        }
                }
        }
        printf("passed!\n");

        printf("testing solve_puzzle_random with unsolvable puzzle...\n");
        if (solve_puzzle_random(unsolvable)){
                fprintf(stderr, "unsolvable puzzle test failed\n");
                return 1;
        }
        printf("passed!\n");
        printf("testing solve_puzzle_random with solvable puzzle...\n");
        printf("solving: \n");
        sudoku_print(solvable2);
        if (!solve_puzzle_random(solvable2)){
                fprintf(stderr, "solvable puzzle test failed\n");
                return 1;
        }
        printf("solution:\n");
        sudoku_print(solvable2);
        for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                        if (!sudoku_isvalid(solvable2, i, j)){
                                fprintf(stderr, "solvable puzzle test failed\n");
                                return 1;
                        }
                }
        }
        printf("passed!\n");
        printf("testing unique_solution with non unique puzzle...\n");
        if(unique_solution(blank)){
                fprintf(stderr, "non unique puzzle test failed\n");
                return 1;
        }
        printf("passed!\n");
        printf("testing unique_solution with unique puzzle...\n");
        sudoku_edit(solvable, 0, 0, 0);
        sudoku_edit(solvable, 0, 1, 0);
        sudoku_edit(solvable, 1, 0, 0);
        sudoku_edit(solvable, 1, 1, 0);
        if(!unique_solution(solvable)){
                fprintf(stderr, "unique puzzle test failed\n");
                return 1;
        }
        printf("passed!\n");
        sudoku_delete(solvable);
        sudoku_delete(solvable2);
        sudoku_delete(unsolvable);
        sudoku_delete(blank);
        return 0;
}
#endif
