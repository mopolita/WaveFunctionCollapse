CC = gcc
CFLAGS = -Wall -Wextra
LDLIBS = -fsanitize=address

all: main

main: main.o sudoku.o solver.o
sudoku.o: sudoku.c sudoku.h
solver.o: solver.c solver.h

.PHONY: clean

clean:
    ${RM} *.o
    ${RM} main