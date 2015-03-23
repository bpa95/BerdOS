all: ../lib/libhelpers.so
	gcc lenwords.c -I../lib/ -L../lib/ -lhelpers -o lenwords

../lib/libhelpers.so:
	$(MAKE) -C ../lib
