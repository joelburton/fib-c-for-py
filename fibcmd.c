/** Command line program to show fibonacci numbers. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "fibgmp.h"

int main(int argc, char *argv[]) {
    const int count = (argc == 2) ? atoi(argv[1]) : 50;

    clock_t time1 = clock();
    char *out = fib(count);
    clock_t time2 = clock();
    char *fast_out = fibfast(count);
    clock_t time3 = clock();
    printf("fib : %s\n", out);
    printf("fast: %s\n", fast_out);

    double speed1 = (time2 - time1) / (double) CLOCKS_PER_SEC;
    double speed2 = (time3 - time2) / (double) CLOCKS_PER_SEC;
    printf("speeds: %.5lf versus %.5lfs\n", speed1, speed2);

    free(out);       // tidy: release memory used by our
    free(fast_out);  //   dynamically-allocated strings
}
