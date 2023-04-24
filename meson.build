project('ciu', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

add_global_arguments('-D=_debug -std=c++17 -Wall -ftrapv', language : 'cpp')

inc = include_directories('include')
subdir('src')
subdir('tests')
