def fib(count):
    a = 0
    b = 1

    for i in xrange(count):
        a, b = b, a + b
        
    return b


if __name__ == "__main__":
    from sys import argv
    print fib(int(argv[1]))
