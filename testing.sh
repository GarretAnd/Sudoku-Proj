#!/bin/bash

#Author: cs50maybemajors
#Date: 5/27/2020
#Purpose: CS50 Final Project
# Tests sudoku.c

num=50
if [ $# -eq 1 ]; then
	num=$1
fi

echo Testing too few arguments:
./sudoku
if [ $? -ne 1 ]
then
	echo "too few arguments test failed"
	exit 1
fi
echo
echo Testing too many arguments:
./sudoku create randomword
if [ $? -ne 1 ]
then
        echo "too many arguments test failed"
	exit 1
fi
echo
echo Testing invalid argument:
./sudoku randomword
if [ $? -ne 2 ]
then
        echo "invalid argument test failed"
        exit 1
fi
echo
echo Testing sudoku create, saving into file 'testfile':
./sudoku create > testfile
if [ $? -ne 0 ]
then
        echo "sudoku create failed"
        exit 1
fi
echo
echo Testing sudoku solve on 'testfile':
./sudoku solve < testfile
if [ $? -ne 0 ]
then
        echo "sudoku solve failed"
        exit 1
fi
echo
echo Fuzz testing:
i=1
while [ $i -le $num ]
do
	echo Generated Puzzle 1:
	./sudoku create > testfile1
	cat testfile1
	sleep 1
	echo Generated Puzzle 2:
	./sudoku create > testfile2
	cat testfile2
	echo Differences in the two puzzles:
	diff testfile1 testfile2 2> /dev/null 1>/dev/null # exit code 0 if no differences, nonzero if differences exist
	ST=$?

	if [[ $ST -ne 0 ]] # if there are differences
	then # print the differences and exit
		echo Differences exist.	
	else # otherwise exit 0
		echo No differences exist! fuzz test failed
		exit 1
	fi
	echo Solved Puzzle 1:
	./sudoku solve < testfile1
	if [ $? -ne 0 ]
	then
		echo "solving puzzle 1 failed"
	fi
	echo Solved Puzzle 2:
	./sudoku solve < testfile2
	if [ $? -ne 0 ]
	then
        	echo "solving puzzle 2 failed"
        	exit 1
	fi	
	i=$((i + 1))
done
echo "all tests passed sucessfully!"
exit 0
