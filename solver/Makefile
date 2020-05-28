#variables

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I../common
PROG = solvertest

#rules
all: solver.o ${PROG}

solver.o: solver.c
	${CC} ${CFLAGS} $^ -c

${PROG}: ${PROG}.c solver.o ../common/libsudoku.o ../common/random.o
	${CC} ${CFLAGS} $^ -o ${PROG}

#phony targets
.PHONY: clean test

test: ${PROG}
	./${PROG}

clean:
	rm -f *.o

