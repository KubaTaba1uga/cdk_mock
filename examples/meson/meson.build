project('mytest_project', 'c')

c_minilib_mock_proj = subproject('c_minilib_mock')
c_minilib_mock_dep = c_minilib_mock_proj.get_variable('c_minilib_mock_dep')

mock_flags_gen_script = c_minilib_mock_proj.get_variable('wraps_gen_script')

exe = executable('mytest', ['main.c', 'test_main.c', 'lib.c'],
  dependencies: [c_minilib_mock_dep],
  link_args: run_command(mock_flags_gen_script, ['foo']).stdout().strip().split(' ')
)
