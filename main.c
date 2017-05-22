#include <stdio.h>
#include <assert.h>
#include "header1.h"
#include "header2.h"
#include "test.h"
#include "test2.h"
#include "slist.h"

SLIST(int);
SLIST(float);

int main()
{
    test();
    test2();

    header1_test();

    SList_int l;
    SLIST_INIT(int, l);
    bool success = false;
    SLIST_ADD(int, l, 9, success);
    assert(success);

    printf("l.first: %p\n", (void *) l.first);
    printf("l.first->data: %d\n", l.first->data);
    printf("l.first->next: %p\n", (void *)l.first->next);

    /*
    SList_float f;
    SLIST_INIT(float, f);
    printf("f.first: %p\n", (void *) f.first);
    */

    /*
    SList_int i;
    SList_float f1;
    //SList_float f2 = i; //error
    SList_float f2 = f1;
    */

    return 0;
}
