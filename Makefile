#variables

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I./creator -I./solver -I./common
MEMTEST = valgrind --leak-check=full --show-leak-kinds=all
PROG = sudoku

#rules

$(PROG): $(PROG).c ./common/libsudoku.o ./common/random.o  ./creator/creator.o ./solver/solver.o
	$(CC) $(CFLAGS) $^ -o $@


#phony targets
.PHONY: clean test

test: $(PROG)
	./testing.sh
	make -C solver test
	make -C common test
	make -C creator test

memtest: $(PROG)
	$(MEMTEST) ./$<

clean:
	rm -rf *.o
	rm -rf sudoku
	rm -rf core
	rm -rf testfile
	rm -rf testfile1
	rm -rf testfile2
	make -C solver clean
	make -C common clean
	make -C creator clean
