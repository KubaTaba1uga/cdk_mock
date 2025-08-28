#include <stdio.h>

#include "cdk_mock.h"
#include "lib.h"

CDKM_MOCKABLE(int bar(void)) { return 888; }
CDKM_MOCKABLE_DUPLICATE(bar);

#ifdef CDK_MOCK_ENABLE
int _main(void) {
#else
int main(void) {
#endif
  printf("bar returned: %d\n", bar());
  printf("foo returned: %d\n", foo());
  return 0;
}
