all: filter

filter: libhelpers
	gcc filter.c -o filter -L../lib -I../lib -Wl,-rpath=../lib -lhelpers

libhelpers:
	$(MAKE) -C ../lib

clean:
	rm -f ./filter
