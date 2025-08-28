#include <stdio.h>

#include "cdk_mock.h"

CDKM_MOCKABLE(int add(int a, int b)) { return a + b; }

CDKM_MOCKABLE_STATIC(int static_add(int a, int b)) { return a + b; }

int main(void) {
  int result = add(1, 2);

  printf("Addition result is: %d\n", result);

  result = static_add(1, 2);

  printf("Addition result is: %d\n", result);

  return 0;
}
