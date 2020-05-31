# CS50 Final Project
## cs50maybecsmajor
## CS50 Spring 2020

### sudokugraphics.py

`sudokugraphics.py` utilizes the sudoku c program to create a gui which can create and solve valid sudoku puzzles

### Usage

`sudokugraphics.py` can be run from the commandline through a python environment and takes an optional parameter detailing the filepath to a valid sudoku file.
- if no parameter is given it will default to creating a random sudoku puzzle in a file called sudokufile

examples:
- ```python sudokugraphics.py```
- ```python sudokugraphics.py sudokuFile```

### Requirements
`sudokugraphics.py` makes use of cs1lib.py which is a python graphics library created by dartmouth college for use by cs1 students
- this library is dependent on the PyQt5 lib which can be installed through pip
