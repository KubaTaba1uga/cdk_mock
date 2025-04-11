#include <stdio.h>

#include "lib.h"

#include <c_minilib_mock.h>

MOCKABLE(int bar(void)) { return 888; }
MOCKABLE_DUPLICATE(bar);

#ifdef DEBUG
int _main(void) {
#else
int main(void) {
#endif
  printf("bar returned: %d\n", bar());
  printf("foo returned: %d\n", foo());
  return 0;
}
