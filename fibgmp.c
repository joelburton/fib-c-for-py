#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "fibgmp.h"


/** Iterative fibonacci, using gmp for huge numbers. */

extern char *fib(int count) {
    char *cout;   // string result we'll return
    mpz_t a, b, out;
    mpz_inits(a, b, out, NULL);

    mpz_set_d(b, 1);  // a is already set to 0 by mpz_init

    for (int i = 0; i < count; ++i) {
        mpz_add(out, a, b); // out = a + b
        mpz_set(a, b);      // a = b
        mpz_set(b, out);    // b = out
    }

    // get string of answer
    gmp_asprintf(&cout, "%Zd", out);

    // clear memory used for gmp's mpz_t vars
    mpz_clears(a, b, out, NULL);

    return cout;
}


/** Fast version of fib -- uses semi-closed form from gmp */

extern char *fibfast(int count) {
    char *cout;   // string result we'll return
    mpz_t out;
    mpz_init(out);

    mpz_fib_ui(out, count + 1);

    // get string of answer
    gmp_asprintf(&cout, "%Zd", out);

    // clear memory used by out
    mpz_clear(out);

    return cout;
}
