all: stdg

FLAGS=-g

STDGI=.

stdg: files.o vector.o string.o
	gcc -shared -o stdg.so $^

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@ -I $(STDGI)

#vector: stdg examples/vector.c stdg.h
#	gcc examples/vector.c stdg.o -o vector -I .
