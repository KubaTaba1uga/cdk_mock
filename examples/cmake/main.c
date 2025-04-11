#include <stdio.h>

#include "lib.h"
#include "main.h"

MOCKABLE(int bar(void)) { return 89; }
MOCKABLE_DUPLICATE(bar);

#ifdef DEBUG
int _main(void) {
#else
int main(void) {
#endif
  printf("foo returned: %d\n", foo());
  return 0;
}
