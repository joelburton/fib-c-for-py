/** PostgreSQL User Defined Function wrapper for Fibonacci.
 *
 * This is straightforward idea: wrap our fast-fibonacci C
 * function so it can be used in PostgreSQL. PG has a bunch
 * of macros to help make a C-based UDF; see section 36.9
 * in the PostgreSQL docs.
 *
 * Joel Burton <joel@joelburton.com>
 *
 */

#include "postgres.h"
#include "fmgr.h"
#include <string.h>

char *fibfast(int count);

// In order to trust that this code contains valid Postgres stuff,
// PostgreSQL requires that this get a "magic header" (a specific bit
// of code it can recognize); this macro emits that magic header.
PG_MODULE_MAGIC;

// Register that this function is a user defined function for PG.
PG_FUNCTION_INFO_V1(pgfib);


/** PG user defined function to calculate fib.
 *
 * Takes one real argument: int count of which fib # to return
 *
 * Returns a PostgreSQL "text" data answer
 */

Datum pgfib(PG_FUNCTION_ARGS) {

    // Get the first (and only) func argument: an integer of the
    // count of the Fibonacci number, using a special PG macro
    // (int32 is a PG type for an integer number that is guaranteed
    // to be 32 bits lots)
    int32 count = PG_GETARG_INT32(0);

    // Get the string anwer for our fib and note its length
    char *fibstring = fibfast(count);
    int len = strlen(fibstring) + 1;

    // Request memory (using Postgres-specific palloc()) for our
    // output string (being sure to make space for the PG text
    // header, with length VARHDRSZ).
    text *out = (text *) palloc(len + VARHDRSZ);
    SET_VARSIZE(out, len + VARHDRSZ);

    // memcpy() is a standard C library call; here, it means
    // "copy len bytes from fibstring to VARDATA(out)" ---
    // VARDATA() is a PG macro that finds the actual-char* part 
    // of the PG text type
    memcpy(VARDATA(out), fibstring, len);

    // We no longer need the allocated memory for our original
    // answer (we've copied it into out)
    free(fibstring);

    // Using a PG macro, return our answer as a string 
    PG_RETURN_TEXT_P(out);
}
