def fib(count):
    a = 0
    b = 1

    for i in xrange(count):
        a, b = b, a + b
        
    return b
