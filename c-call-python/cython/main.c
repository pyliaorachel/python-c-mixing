#include <Python.h>
#include "speedup_dev_and_performance.h"

// Wrapper method for python function 
int _complex_and_slow_calc(int x, int a, int b) {
    PyObject *pRes;
    int res;

    // Call function with args
    pRes = complex_and_slow_calc(PyLong_FromLong(x), PyLong_FromLong(a), PyLong_FromLong(b));

    // If no failure, parse the return value into standard c types
    if (pRes == NULL)
        return -1;
    res = PyLong_AsLong(pRes);

    // Decrement reference counts to avoid memory leak
    Py_DECREF(pRes);

    return res;
}

// Main
int main() {
    // Init Python interpreter
    Py_Initialize();
    
    // Init module & call Python function
    printf("%d\n", _complex_and_slow_calc(3, 2, 4));

    // Frees memory allocated by Python interpreter 
    Py_Finalize();
}
