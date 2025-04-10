#include "example_2.h"

#include "stdio.h"

// We need to declare somwhere orginal function. Declaring it in
//  test makes src code cleaner.
int real_add(int a, int b);

int add(int a, int b) {
  puts("Mock called");
  return real_add(a, b);
}

void test_main() { _main(); }

int main() { test_main(); }
