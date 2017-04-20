# Makefile to build pgfib extension.

OBJS = pgfib.o ../fibgmp.o
MODULE_big = pgfib
EXTENSION = pgfib
DATA = pgfib--1.0.sql
DOCS = README.pgfib

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)

test: all
	@psql -c "CREATE OR REPLACE FUNCTION fib(INT) RETURNS TEXT AS '$(shell pwd)/pgfib.so', 'pgfib' LANGUAGE C STRICT; SELECT FIB(10);" | grep ' 89' > /dev/null || echo "*** FAIL"
