all: foreach

foreach: libhelpers
	gcc foreach.c -o foreach -L../lib -I../lib -Wl,-rpath=../lib -lhelpers

libhelpers:
	$(MAKE) -C ../lib

clean:
	rm -f ./foreach
