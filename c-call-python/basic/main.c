#include <Python.h>

// Wrapper method for python function 
int complex_calc(int x, int a, int b) {
    PyObject *pModule, *pFunc, *pArgs, *pKargs, *pRes;
    int res;

    // Import Python module & function
    pModule = PyImport_Import(PyUnicode_FromString("speedup_dev"));
    pFunc = PyObject_GetAttrString(pModule, "complex_calc");
    
    // Create args object to pass in
    pArgs = Py_BuildValue("(i)", x);
    pKargs = Py_BuildValue("{s:i, s:i}", "a", a, "b", b);

    // Call function with args
    pRes = PyObject_Call(pFunc, pArgs, pKargs);

    // If no failure, parse the return value into standard c types
    if (pRes == NULL)
        return -1;
    res = PyLong_AsLong(pRes);

    // Decrement reference counts to avoid memory leak
    Py_DECREF(pModule);
    Py_DECREF(pFunc);
    Py_DECREF(pArgs);
    Py_DECREF(pKargs);
    Py_DECREF(pRes);

    return res;
}

// Main
int main() {
    // Init Python interpreter
    Py_Initialize();
    
    // Set Python search path
    PySys_SetPath(Py_DecodeLocale(".", NULL));
 
    // Call Python function
    printf("%d\n", complex_calc(3, 2, 4));

    // Frees memory allocated by Python interpreter 
    Py_Finalize();
}
