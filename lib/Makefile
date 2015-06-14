all: libhelpers.so libbufio.so

libhelpers.so: helpers.o
	gcc -shared -o libhelpers.so helpers.o

helpers.o:
	gcc -o helpers.o -c -Wall -fPIC helpers.c

libbufio.so: bufio.o
	gcc -shared -o libbufio.so bufio.o

bufio.o:
	gcc -o bufio.o -c -Wall -fPIC bufio.c

clean:
	rm -f *.o
	rm -f *.so
