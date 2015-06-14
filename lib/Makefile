all: libhelpers.so

libhelpers.so: helpers.o
	gcc -shared -o libhelpers.so helpers.o

helpers.o:
	gcc -o helpers.o -c -Wall -fPIC helpers.c

clean:
	rm -f *.o
	rm -f *.so
