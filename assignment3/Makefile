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

all: list.exe hash.exe

list.exe: src/main.o src/symtablelist.o
	$(CC) $(CFLAGS) $^ -o $@

hash.exe: src/main.o src/symtablehash.o
	$(CC) $(CFLAGS) $^ -o $@


%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	-rm -f *.exe ./src/*.o
