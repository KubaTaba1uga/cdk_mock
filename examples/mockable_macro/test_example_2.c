#include "stdio.h"

// We need to declare somwhere orginal function. Declaring it in
//  test makes src code cleaner.
int add_orig(int a, int b);
int _main(void);

int add(int a, int b) {
  puts("Mock called");
  return add_orig(a, b);
}

void test_main() { _main(); }

int main() { test_main(); }
