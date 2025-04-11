# c_minilib_mock

**`c_minilib_mock`** is a lightweight C mocking library designed for function substitution during testing. It leverages GCC/Clang features like **weak symbols** and **linker wrappers**, enabling flexible mocking with minimal effort.

## ✨ Features

- **Function Mocking**: Replace real implementations with test-specific versions.
- **Weak & Wrapper-Based**: Supports both `__attribute__((weak))` and `--wrap` techniques.
- **Minimal Interface**: Use simple macros like `MOCKABLE()` and `MOCKABLE_DUPLICATE()`.
- **Multi-Build Support**: Works with both **CMake** and **Meson**.
- **Practical Examples**: Comes with usage examples.

## 🧠 Example Usage

Check the usage examples in the respective subdirectories of `examples/`:
- CMake Examples: `examples/cmake/`
- Meson Examples: `examples/meson/`
- Mockable Macro Examples: `examples/mockable_macro/`

Each example demonstrates how to use the provided macros and integration scripts.

## 🧰 Development Tools

- **CMake Function**: `add_mocked_test()` simplifies test definition and linker wrapping.
- **Meson Script**: `wrap_flags_gen.py` generates required `-Wl,--wrap=` flags automatically.
- **Portable Macros**:
  - `MOCKABLE()`: Enables weak substitution.
  - `MOCKABLE_STATIC()`: Makes static functions mockable.
  - `MOCKABLE_DUPLICATE()`: Allows access to original function as `<name>_orig`.

## 📚 Diagram

A visual explanation of when to use **wrapper** vs **weak** method is available at:  
`docs/c-minilib-mock-architecture.drawio`

## 📄 License

MIT License. See [LICENSE](LICENSE) for full text.
