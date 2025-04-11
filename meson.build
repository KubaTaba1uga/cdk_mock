project('c_minilib_mock', 'c')

c_minilib_mock_dep = declare_dependency(
  include_directories: include_directories('include'),
  compile_args: ['-DDEBUG']
)

wraps_gen_script = find_program(files('meson/wrap_flags_gen.py'))
