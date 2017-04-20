from distutils.core import setup, Extension

py_modules = ['fib']

Emodule = Extension('fib',
        libraries=['gmp'],
        include_dirs=['..'],
        sources=['../fibgmp.c', 'pyfib.c'])

setup(name='fib',
        version='1.0',
        description='Descrip of module',
        ext_modules=[Emodule])

