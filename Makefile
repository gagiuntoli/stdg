all: stdg examples

#examples: vector

stdg: files.o vector.o
	gcc -shared -o stdg.so vector.o files.o

vector.o: vector.c
	gcc -c $^ -o $@

files.o: files.c
	gcc -c $^ -o $@

#vector: stdg examples/vector.c stdg.h
#	gcc examples/vector.c stdg.o -o vector -I .
