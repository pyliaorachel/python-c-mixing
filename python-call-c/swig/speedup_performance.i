/* Define module name */
%module speedup_performance

/* Insert code into generated C wrapper code */
%{
#include "speedup_performance.h"
%}

/* List declarations */
int slow_calc(int x, int a = 0, int b = 0);
