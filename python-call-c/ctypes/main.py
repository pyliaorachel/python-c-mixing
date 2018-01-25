from ctypes import *


m = cdll.LoadLibrary('./speedup_performance.so')

print(m.slow_calc(c_int(3), c_int(2), c_int(4)))
