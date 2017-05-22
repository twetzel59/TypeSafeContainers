#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

#include <stdlib.h>
#include <stdbool.h>

//Defines a linked list of a type
#define SLIST(T)                                        \
    typedef struct SList_##T##_Node SList_##T##_Node;   \
    struct SList_##T##_Node {                           \
        T data;                                         \
        SList_##T##_Node *next;                         \
    };                                                  \
                                                        \
    typedef struct {                                    \
        SList_##T##_Node *first;                        \
    } SList_##T //No ; so that usage can have one

//Initializes a linked list of type T
#define SLIST_INIT(T, _slist_list)  \
    do {                            \
        SList_##T _slist_init;      \
        _slist_init.first = NULL;   \
                                    \
        _slist_list = _slist_init;  \
    } while(0)

//Adds an item to the end of a linked list
#define SLIST_ADD(T, _slist_list, _slist_data, _slist_result)   \
    do {                                                        \
        SList_##T _slist_add = _slist_list;                     \
        _slist_result = true;                                   \
                                                                \
        SList_##T##_Node *_slist_add_new_node =                 \
                malloc(sizeof *_slist_add_new_node);            \
                                                                \
        if(_slist_add_new_node) {                               \
            _slist_result = true;                               \
                                                                \
            _slist_add_new_node->data = (_slist_data);          \
            _slist_add_new_node->next = NULL;                   \
            _slist_add.first = _slist_add_new_node;             \
        } else {                                                \
            _slist_result = false;                              \
        }                                                       \
                                                                \
        _slist_list = _slist_add;                               \
    } while(0)

#endif // SLIST_H_INCLUDED
