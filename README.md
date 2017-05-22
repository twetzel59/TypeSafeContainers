# TypeSafeContainers
TSC for C is a collection of generic containers for C that actually are type safe, easy, and un-confusing.

## Currently WIP, not ready just yet

## Planned:
Arrays, linked lists, hash tables...

## Example:

	#include <assert.h>
	#include <stdio.h>
	#include "slist.h"

	#ifndef SLIST_INT
	SLIST(int);
	#define SLIST_INT
	#endif

	int main() {
		SList_int l;
        SLIST_INIT(int, l);
        bool success = false;
        SLIST_ADD(int, l, 9, success);
        assert(success);

        printf("l.first: %p\n", (void *) l.first);
        printf("l.first->data: %d\n", l.first->data);
        printf("l.first->next: %p\n", (void *)l.first->next);

        SLIST_ADD(int, l, 11, success);
        assert(success);

        SLIST_ADD(int, l, 12, success);
        assert(success);

        SLIST_ADD(int, l, 13, success);
        assert(success);

        SLIST_INSERT(int, l, l.first->next, 10, success);
        assert(success);

        SLIST_INSERT(int, l, l.first, 8, success);
        assert(success);

        SLIST_INSERT(int, l, l.first, 7, success);
        assert(success);

        SLIST_INSERT(int, l, l.first, 6, success);
        assert(success);

        SLIST_ADD(int, l, 14, success);
        assert(success);

        puts("listing:");

        for(SList_int_Node *i = l.first; i != NULL; i = i->next) {
            printf("node (%p): %d\n", (void *)i, i->data);
        }

        SLIST_FREE(int, l);

	    return 0;
	}
