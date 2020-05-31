import os
from cs1lib import *

# constants for GUI
WIN_X = 360
WIN_Y = 400
NEW_PUZZLE_START_X = 10
NEW_PUZZLE_START_Y = WIN_Y-35
SOLVE_PUZZLE_START_X = WIN_X/2+20
SOLVE_PUZZLE_START_Y = WIN_Y-35

# file corresponding to sudoku
sudokuFile = "sudokufile"

# updates the GUI according to the sudoku file's contents
def draw_sudoku():
    board = open(sudokuFile, "r")

    board_data = [["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"],
                  ["0","0","0","0","0","0","0","0","0"]]

    y = 0
    x = 0
    line = board.readline()
    while line != "":  # read all lines in sudoku file
        for word in line.split():  # Iterates through it and splits it up then puts each one in our board data array
            board_data[x][y] = word
            x += 1
            if x == 9:  # after 9 elements move to next line of sudoku
                x = 0
                y += 1
        line = board.readline()

    i = 0
    set_font_size(12)
    while i < 9:  # loop through each row
        j = 0
        while j < 9:  # loop through each column
            draw_text(board_data[i][j], (40*i + 15), (40*j + 30))  # draw text at each box to match what was read from sudoku file
            j += 1
        i += 1
    board.close()


def run():
    set_clear_color(1, 1, 1)
    clear()

    # initialize all boxes
    i = WIN_X - 40
    while i > 0:
        set_stroke_width(1)
        if i == 120 or i == 240:  # thick lines for boxes
            set_stroke_width(3)
        draw_line(i, WIN_Y-40, i, 0)
        draw_line(WIN_X, i, 0, i)
        i -= 40

    # draw new puzzle button
    draw_rectangle(NEW_PUZZLE_START_X, NEW_PUZZLE_START_Y, WIN_X/2-30, 30)
    draw_text("new puzzle", 20, WIN_Y - 15)
    # draw solve puzzle button
    draw_rectangle(SOLVE_PUZZLE_START_X, SOLVE_PUZZLE_START_Y, WIN_X/2-30, 30)
    draw_text("solve", WIN_X/2+30, WIN_Y-15)

    draw_sudoku() # fill in the board according to sudoku file


# generates a new sudoku puzzle
def create_sudoku():
    os.system("./../sudoku create >"+sudokuFile)  # use sudoku program to  create new random puzzle


# solves the sudoku puzzle in sudoku file
def solve_sudoku():
    board = open(sudokuFile, "r")
    boardContents = board.read() # get contents of sudoki file
    os.system("echo \""+boardContents+"\" | ./../sudoku solve >"+sudokuFile)  # pipe contents of sudoku file to sudoku solve
    board.close()


# checks to see if click is inside a button and calls corresponding functions
def on_click(mx, my):
    if mx > SOLVE_PUZZLE_START_X and mx < SOLVE_PUZZLE_START_X+WIN_X/2-30 and my > SOLVE_PUZZLE_START_Y and my < SOLVE_PUZZLE_START_Y+30:
        solve_sudoku()
    elif mx > NEW_PUZZLE_START_X and mx < NEW_PUZZLE_START_X+WIN_X/2-30 and my > NEW_PUZZLE_START_Y and my < NEW_PUZZLE_START_Y+30:
        create_sudoku()


if __name__ == "__main__":
    if len(sys.argv) == 2:
        sudokuFile = sys.argv[1]
    else:
        create_sudoku()
    start_graphics(run, frames=1, framerate=10, width=WIN_X, height=WIN_Y, mouse_press=on_click)
