
CREATE FUNCTION fib(int) RETURNS text
  AS '$libdir/pgfib.so', 'pgfib' 
  LANGUAGE C STRICT;
