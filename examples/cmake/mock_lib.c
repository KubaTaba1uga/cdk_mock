#include <stdio.h>

int __real_bar(void);
int __wrap_foo(void) { return 999; }

int bar(void) {
  puts("Mocked called");
  return __real_bar();
}
