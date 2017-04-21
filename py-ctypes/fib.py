import ctypes

# Dynamically load fib library from shared object library
lib = ctypes.CDLL("../fibgmp.so")

# Bind our names
fib = lib.fib
fast = lib.fibfast

# Tell it that the return types are char*
fib.restype = ctypes.c_char_p
fast.restype = ctypes.c_char_p


if __name__ == "__main__":
    from sys import argv
    print fib(int(argv[1]))

