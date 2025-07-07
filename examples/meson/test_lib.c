#include <assert.h>
#include <stdio.h>

#include "lib.h"

int main(void) {
  assert(111 == bar());
  printf("bar returned: %d\n", bar());
  assert(999 == foo());
  printf("foo returned: %d\n", foo());

  return 0;
}
