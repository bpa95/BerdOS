all: bufio

bufio: libbufio
	gcc bufcat.c -o bufcat -L../lib -I../lib -Wl,-rpath=../lib -lbufio

libbufio:
	$(MAKE) -C ../lib

clean:
	rm -f ./bufcat
