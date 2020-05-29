#variables

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I../common
TESTFLAGS = -DTESTMODE
PROG = solver

#rules
all: solver.o ${PROG}test

solver.o: solver.c
	${CC} ${CFLAGS} $^ -c

${PROG}test: ${PROG}.c ../common/libsudoku.o ../common/random.o
	${CC} ${CFLAGS} ${TESTFLAGS} $^ -o ${PROG}test

#phony targets
.PHONY: clean test

test: ${PROG}test
	./${PROG}test

clean:
	rm -f *.o
	rm -f core
	rm -f ${PROG}test

