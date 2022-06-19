gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')
gtest_main_dep = gtest_proj.get_variable('gtest_main_dep')


header_tests = ['myarray', 'mylist']

foreach header_test: header_tests
  e = executable(
    'test_' + header_test, 
    header_test + '.cc', 
    include_directories: include,
    dependencies: [gtest_dep, gtest_main_dep]
  )
  test(header_test, e)
endforeach


# test_pairs = [['myarray', myarray]]

# foreach test_pair: test_pairs
#   e = executable(
#     'test_' + test_pair[0], 
#     test_pair[0] + '.cc', 
#     link_with: test_pair[1], 
#     include_directories: include,
#     dependencies: [gtest_dep, gtest_main_dep]
#   )
#   test(test_pair[0], e)
# endforeach
