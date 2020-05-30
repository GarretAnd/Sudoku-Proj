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

def run():
    WIN_X = 360
    WIN_Y = 360
    set_clear_color(1, 1, 1)
    clear()

    i = WIN_X - 40
    while i > 0:
        set_stroke_width(1)
        if i == 120 or i == 240:
            set_stroke_width(3)

        draw_line(i, WIN_Y, i, 0)
        draw_line(WIN_X, i, 0, i)
        i -= 40

    i = 0

    set_font_size(12)
    while i < 360:
        j = 0
        while j < 360:
            draw_text("0", i + 15, j + 30)
            j += 40
        i += 40


start_graphics(run, framerate=100, width=360, height=360)
