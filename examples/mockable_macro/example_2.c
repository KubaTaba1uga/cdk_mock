#include <c_minilib_mock.h>

#include <stdio.h>

MOCKABLE(int add(int a, int b)) { return a + b; }
MOCKABLE_DUPLICATE(add);

#ifdef ENABLE_MOCKS
int _main(void) {
#else
int main(void) {
#endif
  int result = add(1, 2);

  printf("Addition result is: %d\n", result);

  return 0;
}
