all: ../lib/libhelpers.so
	gcc revwords.c -I../lib/ -L../lib/ -lhelpers -o revwords

../lib/libhelpers.so:
	$(MAKE) -C ../lib
