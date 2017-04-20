fib.so: pyfib.c setup.py
	python setup.py build_ext --inplace

install: fib.so
	python setup.py install

test: fib.so
	@python -c "import fib; assert fib.fib(10) == '89'"
	@python -c "import fib; assert fib.fast(10) == '89'"

clean: 
	rm -rf build
	rm -f fib.so

