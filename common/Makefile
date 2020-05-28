# Makefile for 'libsuduko' module
# Heavily based on makefile from 'bag' module
#
# David Kotz, April 2016, 2017
# updated by Xia Zhou, July 2016, 2018, January 2019
# updated by Temi Prioleau, January 2020
# Modified by Quinn Spraut, May 2020

PROG = libsudokutest
OBJS =

# uncomment the following to turn on verbose memory logging
# TESTING=-DMEMTEST
UNITTEST=-DTESTMODE

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING)
CC = gcc
MAKE = make

all: libsudoku.o random.o

libsudoku.o: libsudoku.h libsudoku.c
random.o: random.c random.h

$(PROG): $(OBJS) libsudoku.c
	$(CC) $(CFLAGS) $(UNITTEST) $^ $(LIBS) -o $@


.PHONY: test clean

test: $(PROG)
	./$(PROG)

clean:
	rm -f *~ *.o *.dSYM
	rm -f $(PROG)
