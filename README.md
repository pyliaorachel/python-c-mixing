# python-c-mixing

Examples of mixing Python and C.

## Python call C

###### Basic

```bash
$ cd python-call-c/basic

# Build module, generates *.so in the same directory
$ python3 setup.py build_ext --inplace
```

```python
# In python
from speedup_performance import slow_calc

slow_calc(3, a=2, b=4)
>>> 10
```
