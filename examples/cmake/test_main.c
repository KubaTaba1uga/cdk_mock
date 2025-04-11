#include <stdio.h>

// mock implementation
int __wrap_foo(void) { return 999; }
int _main(void);

void test_main() { _main(); }

int main() { test_main(); }
