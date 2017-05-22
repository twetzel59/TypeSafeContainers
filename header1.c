#include "header1.h"
#include <stdio.h>
#include "header2.h"

void header1_test() {
    puts("header1_test");

    Vector_int v;
    VECTOR_INIT(int, v);

    header2_test(&v);

    printf("%d\n", v.capacity);
}

/*
void header1_test(Vector_int *v) {
    puts("header1_test");
    v->capacity++;

    header2_test(v);
}
*/
