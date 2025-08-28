# C Development Kit: Mock

## Introduction


**C Development Kit (CDK)** is a set of lightweight, MIT-licensed libraries that make C development on Linux simpler and more consistent. Each package focuses on a specific problem area.

**C Development Kit (CDK): Mock** provides a simple and flexible way to **mock any function in your C project**, making it easier to write unit tests without rewriting or overcomplicating code. It’s designed to be minimal, portable, and integrate smoothly with GCC and CLANG.

## How to use?

Usage example is in `examples` directory, at least one example is prepared for each cmake, meson and compiler only.
Here is simple example showing how to use on of mockable macros:
```
#include <stdio.h>
#include "cdk_mock.h"

/* Production function, marked as mockable */
CDKM_MOCKABLE(int add(int a, int b)) {
    return a + b;   // default implementation
}

/* Expose original symbol so mock can call it if needed */
CDKM_MOCKABLE_DUPLICATE(add);

/* Normal entry point — never ifdef’d */
int main(void) {
    printf("add(2,3) = %d\n", add(2, 3));
    return 0;
}

/* Mock only replaces add() when CDK_MOCK_ENABLE is defined */
#ifdef CDK_MOCK_ENABLE
int add(int a, int b) {
    printf("Mocked add called!\n");
    return add_orig(a, b) + 100; // call original, then modify
}
#endif
```

For productioon build do:
```
gcc main.c -o demo
./demo
```

Output:
```
add(2,3) = 5
```

For tests build do:
```
gcc -DCDK_MOCK_ENABLE main.c -o demo_test
./demo_test
```

Output:
```
Mocked add called!
add(2,3) = 105
```

## How it works?

The approach to mocking presented by the library is based on `wrap` attribute presnted by `ld` (GCC) and `lld` (CLANG). More info can be found here https://linux.die.net/man/1/ld, as `lld` is drop-in replacement for `ld` we can assume they have the same features.

Simple example shoing how wrapping works is here:
```c
#include <stdio.h>
#include <stdlib.h>

void *__real_malloc(size_t);
void *__wrap_malloc(size_t size) {
  printf("malloc called with size %zu\n", size);
  return __real_malloc(size); // Call the real malloc
}

int main(void) {
  char *p = malloc(10); // Will be redirected to __wrap_malloc
  if (p) {
    printf("Allocated successfully!\n");
    free(p);
  }
  return 0;
}
```

To compile and run example use:
```bash
clang main.c -Wl,--wrap=malloc -o wrapdemo
./wrapdemo
```

As you can see wrapping allow for mocking any function from other translation unit, in other woprds wrapping work as long as function to mock is in other `.so` than your code.

If you need to mock function in the same translation unit you need more fancy machineary, `weak` attribute:
```
#include <stdio.h>

/* ---- Production code ---- */
/* Mark the function as weak, so it can be overridden */
__attribute__((weak))
int my_func(void) {
    return 42;   /* Default implementation */
}

void do_work(void) {
    printf("my_func() returned %d\n", my_func());
}

int main(void) {
    do_work();  /* Will call the mock */
    return 0;
}

/* ---- Mock for testing ---- */
int my_func(void) {
    return -1;   /* Mocked version */
}
```

To compile and run example use:
```bash
clang main.c -o weakdemo
./weakdemo
```

These two mocking aproaches are core of this CDK Mock library.

## FAQ

**What is CDK: Mock?**
A small library for function mocking in C — useful for testing code that depends on system calls, external APIs, or other complex functions.

**Why use it?**
Because writing mocks by hand is repetitive and error-prone. This library makes mocking straightforward, with a clean API and no external dependencies.

**What license is used?**
MIT license — free for both open-source and commercial projects.

**Who is it for?**

* Developers writing unit tests in plain C
* Embedded/Linux engineers needing lightweight testing utilities
* Teams wanting to test without pulling in heavy frameworks

