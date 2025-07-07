#include <c_minilib_mock.h>
#include <stdio.h>

#include "lib.h"

int foo() { return 42; }

MOCKABLE(int bar(void)) { return 888; }
MOCKABLE_DUPLICATE(bar);
