#include <assert.h>
#include <stdio.h>

#include "lib.h"

int __wrap_foo() { return 999; }
int __wrap_bar() { return 111; }
