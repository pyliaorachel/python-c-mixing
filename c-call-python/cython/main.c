#include <Python.h>
#include "speedup_dev_and_performance.h"

int main() {
    // Init module & Python interpreter
    PyImport_AppendInittab("speedup_dev_and_performance", PyInit_speedup_dev_and_performance);
    Py_Initialize();
    PyImport_ImportModule("speedup_dev_and_performance");
    
    // Call Python function
    printf("%d\n", complex_and_slow_calc_c(3, 2, 4));

    // Frees memory allocated by Python interpreter 
    Py_Finalize();
}
