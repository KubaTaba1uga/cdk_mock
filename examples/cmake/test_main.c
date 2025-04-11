#include <stdio.h>

int bar_orig(void);
int _main(void);

int __wrap_foo(void) { return 999; }

int bar(void) {
  puts("Mocked called");
  return bar_orig();
}

void test_main() { _main(); }

int main() { test_main(); }
