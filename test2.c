#include "test2.h"
#include <stdio.h>
#include "vector.h"
#include "header2.h"

void test2() {
    Vector_int v;
    VECTOR_INIT(int, v);
    printf("test: %d\n", v.capacity);
}
