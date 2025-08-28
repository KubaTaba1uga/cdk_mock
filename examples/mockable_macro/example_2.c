#include <stdio.h>

#include "cdk_mock.h"

CDKM_MOCKABLE(int add(int a, int b)) { return a + b; }
CDKM_MOCKABLE_DUPLICATE(add);

int main(void) {
  int result = add(1, 2);

  printf("Addition result is: %d\n", result);

  return 0;
}
