#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "fibgmp.h"


/** Iterative fibonacci, using gmp for huge numbers. */

extern char *fib(int count) {
    mpz_t a, b, out;

    mpz_init(a);
    mpz_init(b);
    mpz_init(out);

    mpz_set_d(b, 1);  // a is already set to 0 by mpz_init

    for (int i = 0; i < count; ++i) {
        mpz_add(out, a, b); // out = a + b
        mpz_set(a, b);      // a = b
        mpz_set(b, out);    // b = out
    }

    // return string of answer

    char *cout;
    gmp_asprintf(&cout, "%Zd", out);
    return cout;
}


/** Fast version of fib -- uses semi-closed form from gmp */

extern char *fibfast(int count) {
    mpz_t out;
    mpz_init(out);

    mpz_fib_ui(out, count + 1);

    // return string of answer

    char *cout;
    gmp_asprintf(&cout, "%Zd", out);
    return cout;
}
