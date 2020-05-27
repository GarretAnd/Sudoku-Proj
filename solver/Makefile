#variables

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I../common

#rules
all: solver.o

solver.o: solver.c
	${CC} ${CFLAGS} $^ -c

#phony targets
.PHONY: clean

clean:
	rm -f *.o

