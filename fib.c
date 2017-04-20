/** Simple fibonacci number function. */

#include <stdio.h>
#include <stdlib.h>


/** Return fibonacci number at count */

long fibonacci(int count) {
    static long a = 0, b = 1, out;

    for (int i = 0; i < count; ++i) {
        out = a + b;
        a = b;
        b = out;
    }

    return out;
}


/** Main function: test on command line with "fib 10" */

int main(int argc, char *argv[]) {

    // get int of first argument if provided, else use 50
    const int count = (argc == 2) ? atoi(argv[1]) : 50;

    printf("%ld\n", fibonacci(count));
}
