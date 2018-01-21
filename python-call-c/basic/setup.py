from distutils.core import setup, Extension

speedup_performance_module = Extension('speedup_performance',
                                       sources=['speedup_performance.c'])

setup(name='SpeedupPerformance',
      description='A package containing modules for speeding up performance.',
      ext_modules=[speedup_performance_module],
)
