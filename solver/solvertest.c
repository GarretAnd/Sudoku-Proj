#include "solver.h"
#include "libsudoku.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
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
