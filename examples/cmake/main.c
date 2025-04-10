#include <stdio.h>

#include "main.h"

int foo(void) { return 42; }

int _main(void) {
  printf("foo returned: %d\n", foo());
  return 0;
}
