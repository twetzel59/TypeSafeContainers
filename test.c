#include "test.h"
#include <stdio.h>
#include "vector.h"
#include "header1.h"

#ifndef VECTOR_INT
VECTOR(int);
#define VECTOR_INT
#endif // VECTOR_INT

void test() {
    Vector_int v;
    VECTOR_INIT(int, v);
    printf("test: %d\n", v.capacity);
}
