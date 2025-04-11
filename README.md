# c_minilib_mock

**`c_minilib_mock`** is a lightweight C mocking library designed for function substitution during testing. It leverages GCC/Clang features like **weak symbols** and **linker wrappers**, enabling flexible mocking with minimal effort.

## ✨ Features

- **Function Mocking**: Replace real implementations with test-specific versions.
- **Weak & Wrapper-Based**: Supports both `__attribute__((weak))` and `--wrap` techniques.
- **Minimal Interface**: Use simple macros like `MOCKABLE()` and `MOCKABLE_DUPLICATE()`.
- **Multi-Build Support**: Works with both **CMake** and **Meson**.
- **Practical Examples**: Comes with usage examples.

## 🧠 Example Usage

```c
// app.c
#include <c_minilib_mock.h>
#include <stdio.h>

MOCKABLE(int foo(void)) { return 42; }

#ifdef ENABLE_MOCKS
int _main(void) {
#else
int main(void) {
#endif
    printf("foo: %d\n", foo());
    return 0;
}
```

```c
// test_app.c
int foo(void) { return 999; }
int _main(void);
int main(void) { _main(); }
```

## ⚙️ Build Instructions

### CMake

```sh
./examples/cmake/compile.sh
```

### Meson

```sh
./examples/meson/compile.sh
```

## ✅ Run All Examples

```sh
python3 examples/run.py
```

Each example is compiled and executed. Output indicates if compilation or test execution failed.

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
