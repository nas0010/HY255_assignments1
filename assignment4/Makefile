
###################################################
#
# file: Makefile
#
# @Author:   Iacovos G. Kolokasis
# @Version:  10-02-2022
# @email:    kolokasis@csd.uoc.gr
#
# Makefile
#
####################################################

CC = gcc
CFLAGS = -Wall -ansi -pedantic -g

all: sudoku

sudoku: src/sudoku.o src/grid.o
	$(CC) $(CFLAGS) $^ -o $@	

grid.o: src/grid.c src/grid.h
	$(CC) $(CFLAGS) $^ -o $@

sudoku.o: src/sudoku.c src/grid.h src/sudoku.h
	$(CC) -c -o $@ $<

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	-rm -f *.exe ./src/*.o


