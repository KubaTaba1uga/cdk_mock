project('mytest_project', 'c')

c_minilib_mock_proj = subproject('c_minilib_mock')
c_minilib_mock_dep = c_minilib_mock_proj.get_variable('c_minilib_mock_dep')

# meson do not allow for user specified functions, so this is as close as we
#  can get to simulating function. This script generates linker flags, which
#  need to be included into the test.
mock_flags_gen_script = c_minilib_mock_proj.get_variable('wraps_gen_script')


exe = executable('example_1', ['main.c', 'lib.c'],
  dependencies: [c_minilib_mock_dep],
  include_directories: include_directories('../../include'),  
)

test_1 = executable('test_example_1', ['test_lib.c', 'lib.c'],
  dependencies: [c_minilib_mock_dep],
  include_directories: include_directories('../../include'),
  c_args: ['-DENABLE_MOCKS'],  
  link_args: run_command(mock_flags_gen_script, ['foo'], check: true).stdout().strip().split(' ')
)

test('test_example_1', test_1)

mocked_lib = library('mocked_lib',
                  sources: ['lib.c', 'mock_lib.c'],
                  include_directories: include_directories('.', '../../include'),
		  
)

test_2 = executable('test_example_2', ['test_lib.c'],
  dependencies: [c_minilib_mock_dep],
  c_args: ['-DENABLE_MOCKS'],
  link_with: mocked_lib,
  link_args: [
              run_command(mock_flags_gen_script, ['foo'], check: true).stdout().strip().split(' ')
	      ]
)
