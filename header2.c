#include "header2.h"
#include <stdio.h>

void header2_test(Vector_int *v) {
    puts("header2_test");
    v->capacity += 2;
}
