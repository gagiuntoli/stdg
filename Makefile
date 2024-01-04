all: stdg examples

#examples: vector
FLAGS=-g

STDGI=.

stdg: files.o vector.o
	gcc -shared -o stdg.so vector.o files.o

vector.o: vector.c
	gcc $(FLAGS) -c $^ -o $@

files.o: files.c
	gcc $(FLAGS) -c $^ -o $@ -I $(STDGI)

#vector: stdg examples/vector.c stdg.h
#	gcc examples/vector.c stdg.o -o vector -I .
