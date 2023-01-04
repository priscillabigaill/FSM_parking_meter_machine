
all: mylib.o main.c
	gcc -O0 -Wall -o main.out main.c mylib.o
	./main.out

mylib.o: mylib/mylib.c
	gcc -O0 -Wall -o mylib.o -c mylib/mylib.c

clear:
	rm -rf *.o
	rm -rf *.out