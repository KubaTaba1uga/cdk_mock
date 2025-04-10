#include <stdio.h>

#include "main.h"

// mock implementation
int __wrap_foo(void) { return 999; }

void test_main() { _main(); }

int main() { test_main(); }
