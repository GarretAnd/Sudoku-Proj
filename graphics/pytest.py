from cs1lib import *


def draw_sudoku(string):
    file = str(string)
    board = open(file, "r")  # Takes in file, converts it to a string, and opens it

    y = 0
    x = 0
    board_data = []

    for word in board.split():  # Iterates through it and splits it up then puts each one in our board data array
        board_data[x][y] = word
        y += 1

        if y == 9:
            y = 0
            x += 1
