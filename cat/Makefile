all: ../lib/libhelpers.so
	gcc cat.c -I../lib/ -L../lib/ -lhelpers -o cat

../lib/libhelpers.so:
	$(MAKE) -C ../lib
