all: libhelpers.so
	gcc revwords.c -o revwords -L../lib/ -I../lib/ -Wl,-rpath=../lib -lhelpers

libhelpers.so:
	$(MAKE) -C ../lib

clean:
	rm -f ./revwords
