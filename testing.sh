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
echo Testing sudoku create, saving into file 'testfile':
./sudoku create > testfile
echo
echo Testing sudoku solve on 'testfile':
./sudoku solve < testfile
echo
echo Fuzz testing:
for i in {1..50}
do
	echo Generated Puzzle 1:
	./sudoku create > testfile1
	cat testfile
	echo Generated Puzzle 2:
	./sudoku create > testfile2
	cat testfile1
	echo Differences in the two puzzles:
	diff ./"$time" $1 2> /dev/null 1>/dev/null # exit code 0 if no differences, nonzero if differences exist
	ST=$?

	if [[ $ST -ne 0 ]] # if there are differences
	then # print the differences and exit
		echo Differences exist.
	else # otherwise exit 0
		echo No differences exist! breaking out...
		break
	fi
	echo Solved Puzzle 1:
	./sudoku solve < testfile1
	echo Solved Puzzle 2:
	./sudoku solve < testfile2
	
done
