testBench = 0 

if testBench == 1 
  project('Fraglog','cpp')
endif

src = files('Fraglog.hpp')
src += files('Fraglog.cpp')
#src += files('main.cpp') 

lib = library('Froglog',src)

if testBench == 1 
  executable('TestBench','main.cpp',link_with : lib)
endif
