#include "solver.h"
#include <stdlib.h>
#include "random.h"

//local prototypes
static void get_unsolved_element(sudoku_t *sudoku, int *row, int *col);
static bool solve_puzzle_backwards(sudoku_t *sudoku);

bool solve_puzzle(sudoku_t *sudoku){
	int row = -1;
	int col = -1;
	get_unsolved_element(sudoku, &row, &col);
	if(row == -1 && col == -1) return true; // check if puzzle is completed
	for(int i = 1; i <= 9; i++){ // loop through all possible values for first incomplete element
		sudoku_edit(sudoku, row, col, i);
		if(sudoku_isvalid(sudoku, row, col) && solve_puzzle(sudoku)) return true; // check if current value can lead to a valid solution
	}
	sudoku_edit(sudoku, row, col, 0);
	return false; // no values where found that could lead to solution
}

bool solve_puzzle_random(sudoku_t *sudoku){
	int row = -1;
        int col = -1;
        get_unsolved_element(sudoku, &row, &col);
        if(row == -1 && col == -1) return true; // check if puzzle is completed
	int i = rand_num()+1; // set random starting point
        for(int j = 0; j < 9; j++){ // loop through all possible values for first incomplete element
                sudoku_edit(sudoku, row, col, i);
                if(sudoku_isvalid(sudoku, row, col) && solve_puzzle_random(sudoku)) return true;
		i++;
		if(i == 10) i = 1; // loop back around after hitting 9 to get all posiibilities
        }
        sudoku_edit(sudoku, row, col, 0);
        return false;
}

bool unique_solution(sudoku_t *sudoku){
	// make copies so we dont solve given puzzle
	sudoku_t *copy1 = sudoku_copy(sudoku);
	sudoku_t *copy2 = sudoku_copy(sudoku);
	if (!solve_puzzle(copy1)) return false; // check that it has a solution
	solve_puzzle_backwards(copy2);
	bool match = sudoku_equal(copy1, copy2); // check if solutions with opposite preferences match
	sudoku_delete(copy1);
	sudoku_delete(copy2);
	return match;
}

/*
 * solves the given sudoku puzzle using backtracing but gives prefence to higher values (opposite of solve_puzzle)
 */
static bool solve_puzzle_backwards(sudoku_t *sudoku){
        int row = -1;
        int col = -1;
        get_unsolved_element(sudoku, &row, &col);
        if(row == -1 && col == -1) return true; // check if puzzle is complete

        for(int i = 9; i >= 1; i--){ // loop through all possible values starting with highes
                sudoku_edit(sudoku, row, col, i);
                if(sudoku_isvalid(sudoku, row, col) && solve_puzzle_backwards(sudoku)) return true; //try to solve puzzle with current value
        }
        sudoku_edit(sudoku, row, col, 0);
        return false;
}

/*
 * stores the first location of a 0 element in given puzzle into row and col
 * makes no changes if there are no 0 elements
 */
static void get_unsolved_element(sudoku_t *sudoku, int *row, int *col){
	for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                        if(sudoku_get(sudoku, i, j) == 0){
                                *row = i;
                                *col = j;
                                return;
                        }
                }
        }
}
#ifdef TESTMODE
// unit tests for solver
int main(void){
	// create unsolvable puzzle
        sudoku_t *unsolvable = sudoku_new();
        sudoku_edit(unsolvable, 0, 0, 1);
        sudoku_edit(unsolvable, 2, 2, 1);
	//create solvable puzzle
        sudoku_t *solvable = sudoku_new();
        sudoku_edit(solvable, 0, 0, 1);
        sudoku_edit(solvable, 2, 2, 3);
        sudoku_edit(solvable, 4, 7, 6);
	// copy solvable puzzle (for later ;))
        sudoku_t *solvable2 = sudoku_copy(solvable);
	// create blank puzzle
        sudoku_t *blank = sudoku_new();
        printf("testing solve_puzzle with unsolvable puzzle...\n");
        if (solve_puzzle(unsolvable)){ // check if it solves the unsolvable puzzle
                fprintf(stderr, "unsolvable puzzle test failed\n");
                return 1;
        }
        printf("passed!\n");
        printf("testing solve_puzzle with solvable puzzle...\n");
        printf("solving: \n");
        sudoku_print(solvable);
        if (!solve_puzzle(solvable)){ // make sure it solves solvable puzzle
                fprintf(stderr, "solvable puzzle test failed\n");
                return 1;
        }
        printf("solution:\n");
        sudoku_print(solvable);
	// check that found solution was valid
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
        if (solve_puzzle_random(unsolvable)){ // check if it solves the unsolvable puzzle
                fprintf(stderr, "unsolvable puzzle test failed\n");
                return 1;
        }
        printf("passed!\n");
        printf("testing solve_puzzle_random with solvable puzzle...\n");
        printf("solving: \n");
        sudoku_print(solvable2);
        if (!solve_puzzle_random(solvable2)){ // make sure it solves solvable puzzle
                fprintf(stderr, "solvable puzzle test failed\n");
                return 1;
        }
        printf("solution:\n");
        sudoku_print(solvable2);
	// check that found solution was valid
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
        if(unique_solution(blank)){ // check that unique solution was not found
                fprintf(stderr, "non unique puzzle test failed\n");
                return 1;
        }
        printf("passed!\n");
        printf("testing unique_solution with unique puzzle...\n");
        sudoku_edit(solvable, 0, 0, 0);
        sudoku_edit(solvable, 0, 1, 0);
        sudoku_edit(solvable, 1, 0, 0);
        sudoku_edit(solvable, 1, 1, 0);
        if(!unique_solution(solvable)){ // check that unique solution was found
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
