#include <Python.h>

// Actual method to be wrapped
int slow_calc(int x, int a, int b) {
    return a * x + b;
}

// Define wrapper methods to be called in Python
static PyObject *_slow_calc(PyObject *self, PyObject *args, PyObject *kwargs) {
    // Arguments
    int x, a = 0, b = 0;
    static char *kwlist[] = {"x", "a", "b", NULL};
    // Return value
    int res;

    // If parse failure (0), return NULL
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "i|ii", kwlist, &x, &a, &b)) {
        return NULL;
    }

    // Call the actual method, store the result
    res = slow_calc(x, a, b);

    // Wrap the return value into PyObject
    return Py_BuildValue("i", res);
}

// Construct the Module's Method Table (list the methods to expose)
static PyMethodDef SpeedupPerformanceMethods[] = {
    // slow_calc method takes in both positional & keyword parameters
    {"slow_calc", (PyCFunction) _slow_calc, METH_VARARGS | METH_KEYWORDS, "A slow calculation method."},
    // Ends with an entry with NULL values
    {NULL, NULL, 0, NULL}
};

// Define the module structure
static struct PyModuleDef speedup_performance_module = {
    PyModuleDef_HEAD_INIT,
    "speedup_performance",
    "A module containing methods with faster performance.",
    -1, // global state
    SpeedupPerformanceMethods
};

// Init method to be called when module gets imported in Python
PyMODINIT_FUNC PyInit_speedup_performance() {
    return PyModule_Create(&speedup_performance_module);
}
