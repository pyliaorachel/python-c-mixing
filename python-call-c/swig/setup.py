from distutils.core import setup, Extension

# Generated C file: <module>_wrap.c
# Note the underscore prefix in the extension name
speedup_performance_module = Extension('_speedup_performance',
                                       sources=['speedup_performance_wrap.c'])

setup(name='SpeedupPerformance',
      description='A package containing modules for speeding up performance.',
      ext_modules=[speedup_performance_module],
)
