project('mytest_project', 'c')

cdk_mock_proj = subproject('cdk_mock')
cdk_mock_dep = cdk_mock_proj.get_variable('cdk_mock_dep')

# meson do not allow for user specified functions, so this is as close as we
#  can get to simulating function. This script generates linker flags, which
#  need to be included into the test.
mock_flags_gen_script = cdk_mock_proj.get_variable('wraps_gen_script')

exe = executable('example_1', ['main.c', 'lib.c'],
  dependencies: [cdk_mock_dep],
)

test = executable('example_1_test', ['main.c', 'mock_lib.c', 'lib.c'],
  dependencies: [cdk_mock_dep],
  c_args: ['-DCDK_MOCK_ENABLE'],  
  link_args: run_command(mock_flags_gen_script, ['foo'], check: true).stdout().strip().split(' ')
)

test('test_example_1', test)

