all: fib fibcmd fibgmp.so

fibcmd: fibcmd.o fibgmp.o
	$(CC) -o fibcmd fibcmd.o fibgmp.o -lgmp

fibgmp.so: fibgmp.c
	rm -f fibgmp.o
	$(CC) -fPIC -shared -o fibgmp.so fibgmp.c -lgmp

test: all
	@./fib 10 | grep 89 > /dev/null || echo "*** FAIL"
	@./fibcmd 10 | grep 'fib : 89' > /dev/null || echo "*** FAIL"
	@./fibcmd 10 | grep 'fast: 89' > /dev/null || echo "*** FAIL"
	cd py-plain; make test
	cd py-cython; make test
	cd py-ctypes; make test
	cd py-ext; make test
	cd postgres; make test

clean:
	rm -f fib test *.o *.so
	cd py-plain; make clean
	cd py-cython; make clean
	cd py-ctypes; make clean
	cd py-ext; make clean
	cd postgres; make clean

