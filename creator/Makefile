# Makefile for 'libsuduko' module
# Heavily based on makefile from 'bag' module
#
# David Kotz, April 2016, 2017
# updated by Xia Zhou, July 2016, 2018, January 2019
# updated by Temi Prioleau, January 2020
# Modified by Garret Andreine, May 2020

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I../common -I../solver

# rules

all: creator.o

solver.o: creator.c
	${CC} ${CFLAGS} $^ -c

# phony targets
.PHONY: clean

clean:
	rm -f *.o
