all: stdg.so tests

FLAGS=-g -fPIC

STDGI=.

tests: map_test

map_test: map_test.c stdg.so
	gcc $(FLAGS) $^ -I $(STDGI) -o $@ 

stdg.so: files.o vector.o string.o map.o
	gcc -shared $(FLAGS) -o stdg.so $^

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@ -I $(STDGI)

test: map_test.o
	./map_test

#vector: stdg examples/vector.c stdg.h
#	gcc examples/vector.c stdg.o -o vector -I .
