from distutils.core import setup
from Cython.Build import cythonize

setup(ext_modules=cythonize('speedup_dev_and_performance.pyx'))
