/** Python extension library for fib */

#include <Python.h>
#include "fibgmp.h"


/** Wrapper function for fib() */

static PyObject *fib_fib(PyObject *self, PyObject *args) {
    int n;

    if (!PyArg_ParseTuple(args, "i", &n))
        return NULL;

    char *out = fib(n);

    return Py_BuildValue("s", out);
}


/** Wrapper function for fast() */

static PyObject *fib_fast(PyObject *self, PyObject *args) {
    int n;

    if (!PyArg_ParseTuple(args, "i", &n))
        return NULL;

    char *out = fibfast(n);

    return Py_BuildValue("s", out);
}


/** Global array of methods we should expose to Python. */

static PyMethodDef FibMethods[] = {
    {"fib",  fib_fib,  METH_VARARGS, "Calculate fib."},
    {"fast", fib_fast, METH_VARARGS, "Calculate fib bigly."},

    // Marker element to show end of list
    {NULL, NULL, 0, NULL},
};


/** Initializer; this is what Python runs to get the module. */

PyMODINIT_FUNC initfib(void) {
    Py_InitModule("fib", FibMethods);
}

