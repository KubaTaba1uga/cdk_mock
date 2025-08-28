#include <stdio.h>

#include "lib.h"

int main(void) {
  printf("bar returned: %d\n", bar());
  printf("foo returned: %d\n", foo());
  return 0;
}
