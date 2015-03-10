all:
	gcc -o helpers.o -c -Wall -fPIC helpers.c
	gcc -shared -o libhelpers.so helpers.o
	rm helpers.o
