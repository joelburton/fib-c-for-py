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
	@psql -c "create extension if not exists pgfib; select fib(10);" | grep ' 89' > /dev/null || echo "*** FAIL"
