#!/bin/bash

#Author: cs50maybemajors
#Date: 5/27/2020
#Purpose: CS50 Final Project
# Tests sudoku.c

echo Testing too few arguments:
./sudoku
echo
echo Testing too many arguments:
./sudoku create randomword
echo
echo Testing invalid argument:
./sudoku randomword
echo
echo Testing functions of libsudoku:
./common/libsudokutest
echo
echo Testing functions of creator:
#./creator/creatortest
echo
echo Testing functions of solver:
#./solver/solvertest
echo
echo Testing sudoku create, saving into file 'testfile':
./sudoku create > testfile
echo
echo Testing sudoku solve on 'testfile':
./sudoku solve < testfile
echo
echo Fuzz testing:
for i in {1..100}
do
	echo Generated Puzzle:
	./sudoku create > testfile
	cat testfile
	echo Solved Puzzle:
	./sudoku solve < testfile
done
