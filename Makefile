all: stdg examples

examples: vector

stdg: stdg.c stdg.h
	gcc -c stdg.c -o stdg.o

vector: stdg examples/vector.c stdg.h
	gcc examples/vector.c stdg.o -o vector -I .
