/** Command line program to show fibonacci numbers. */

#include <stdio.h>
#include <stdlib.h>
#include "fibgmp.h"

int main(int argc, char *argv[]) {
    const int count = (argc == 2) ? atoi(argv[1]) : 50;

    char *out = fib(count);
    printf("fib : %s\n", out);

    char *fast_out = fibfast(count);
    printf("fast: %s\n", fast_out);

    // tidy: release memory used by out and fast_out
    // (nice but not required, at program end, all memory is released)
    free(out);
    free(fast_out);
}
