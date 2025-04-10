#include "../../include/c_minilib_mock.h"

#include <stdio.h>

// If you need orginaly functionality you need to split function into
//  orginal one and mocked one.
int real_add(int a, int b) { return a + b; }

MOCKABLE(int add(int a, int b)) { return real_add(a, b); }

int _main(void) {
  int result = add(1, 2);

  printf("Addition result is: %d\n", result);

  return 0;
}
