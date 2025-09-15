#include "stdio.h"

int __real_add(int a, int b);

int add(int a, int b) {
  puts("Mock called");
  return __real_add(a, b);
}
