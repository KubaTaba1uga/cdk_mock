#include "cdk_mock.h"
#include <stdio.h>

CDKM_MOCKABLE(int add(int a, int b)) { return a + b; }
CDKM_MOCKABLE_DUPLICATE(add);

#ifdef CDK_MOCK_ENABLE
int _main(void) {
#else
int main(void) {
#endif
  int result = add(1, 2);

  printf("Addition result is: %d\n", result);

  return 0;
}
