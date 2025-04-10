project('mytest_project', 'c')

c_minilib_mock_proj = subproject('c_minilib_mock')
c_minilib_mock = c_minilib_mock_proj.get_variable('c_minilib_mock_dep')
add_mocked_test = c_minilib_mock_proj.get_variable('add_mocked_test')

exe = executable('mytest', ['main.c', 'test_main.c', 'lib.c'],
  dependencies: [c_minilib_mock_dep]
)

add_mocked_test('mytest', exe, [], mocked_tests: ['foo'])
