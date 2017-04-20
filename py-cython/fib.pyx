def fib(int count):
    cdef long a, b
    cdef int i
    a = 0
    b = 1
    for i in xrange(count):
        a, b = b, a + b

    return b
