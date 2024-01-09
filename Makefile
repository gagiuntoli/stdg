all: stdg.so tests

FLAGS=-g -fPIC

STDGI=.

tests: map_test vector_test files_test

%_test: tests/%_test.c stdg.so
	gcc $(FLAGS) $^ -I $(STDGI) -o $@ 

stdg.so: files.o vector.o string.o map.o
	gcc -shared $(FLAGS) -o $@ $^

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@ -I $(STDGI)

test: tests
	./vector_test
	./map_test
	./files_test

clean:
	rm -f *.o *.a *.so map_test
