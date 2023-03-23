CC = gcc
CFLAGS = -Wall -Wextra
LDLIBS = -fsanitize=address

all: main

main: main.o sudoku.o
sudoku.o: sudoku.c sudoku.h

.PHONY: clean

clean:
    ${RM} *.o
    ${RM} main