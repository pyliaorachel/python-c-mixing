import math 


def complex_and_slow_calc_p(x, a, b):
    return round(math.sqrt(a * x + b))

cdef public int complex_and_slow_calc_c(int x, int a, int b):
    return round(math.sqrt(a * x + b))

cpdef public int complex_and_slow_calc_cp(int x, int a, int b):
    return round(math.sqrt(a * x + b))
