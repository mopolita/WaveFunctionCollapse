CC = gcc
CFLAGS = -Wall -Wextra
LDLIBS = -fsanitize=address

all: main

main: main.o solver.o sudoku.o
solver.o: solver.c solver.h
sudoku.o: sudoku.c sudoku.h

.PHONY: clean

clean:
    ${RM} *.o
    ${RM} main