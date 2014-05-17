all:	complex.o

complex.o : main.c
	gcc -ansi -pedantic -Wall -g *.c -o complex.o -lm