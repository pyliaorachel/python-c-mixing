# python-c-mixing

Examples of mixing Python and C.

## Python call C

###### Basic

```bash
$ cd python-call-c/basic

# Build module, generates *.so in the same directory
$ python3 setup.py build_ext --inplace

# Run
$ python3 main.py
```

###### SWIG

```bash
$ cd python-call-c/swig

# Build python module with keyword arguments
# Generates *.py, *_wrap.c
$ swig -python -keyword speedup_performance.i

# Build shared object file *.so
$ python3 setup.py build_ext --inplace

# Run
$ python3 main.py

```

## C call Python

###### Basic

```bash
$ cd c-call-python/basic

# Build executable file (python3)
gcc main.c -o main.o $(python3-config --includes) $(python3-config --ldflags)

# Run
$ ./main.o
```

###### Cython

```bash
# Install
$ pip3 install Cython
```

```bash
$ cd c-call-python/cython

# Build module, generates *.so, *.c, *.h in the same directory
$ python3 setup.py build_ext --inplace

# Build executable file (python3)
$ gcc main.c speedup_dev_and_performance.c -o main.o $(python3-config --includes) $(python3-config --ldflags)

# Run
$ ./main.o
```
