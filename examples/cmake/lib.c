#include <stdio.h>

#include "cdk_mock.h"

int foo() { return 42; }

CDKM_MOCKABLE(int bar(void)) { return 888; }
CDKM_MOCKABLE_DUPLICATE(bar);
