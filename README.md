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

## C call Python

###### Basic

```bash
$ cd c-call-python/basic

# Build executable file (python3)
gcc main.c -o main.o $(python3-config --includes) $(python3-config --ldflags)

# Run
$ ./main.o
```
