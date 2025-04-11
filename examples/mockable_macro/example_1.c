#include <c_minilib_mock.h>

#include <stdio.h>

MOCKABLE(int add(int a, int b)) { return a + b; }

MOCKABLE_STATIC(int static_add(int a, int b)) { return a + b; }

#ifdef ENABLE_MOCKS
int _main(void) {
#else
int main(void) {
#endif
  int result = add(1, 2);

  printf("Addition result is: %d\n", result);

  result = static_add(1, 2);

  printf("Addition result is: %d\n", result);

  return 0;
}
