project('ciu', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3'])

gtest_proj = subproject('gtest')

gtest_dep = gtest_proj.get_variable('gtest_dep')
gtest_main_dep = gtest_proj.get_variable('gtest_main_dep')

myarray = library('myarray', 'src/arrays/myarray.cc')
includes = include_directories('src')

e = executable(
  'test_myarray', 
  'tests/myarray.cc', 
  link_with: myarray, 
  include_directories: includes,
  dependencies: [gtest_dep, gtest_main_dep])

# exe = executable('myarray', 'arrays/myarray.cc',
#   install : true)

 test('gtest test', e)
