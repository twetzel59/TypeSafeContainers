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

//Releases memory the linked list was taking. Invalidates the list
#define SLIST_FREE(T, _slist_list)                                  \
    do {                                                            \
        SList_##T _slist_free = _slist_list;                        \
                                                                    \
        SList_##T##_Node *_slist_i = _slist_free.first;             \
        while(_slist_i) {                                           \
            SList_##T##_Node *_slist_next_temp = _slist_i->next;    \
                                                                    \
            printf("%d\n", _slist_i->data);                         \
            free(_slist_i);                                         \
            _slist_i = _slist_next_temp;                            \
        }                                                           \
    } while(0)

//Adds an item to the end of a linked list
#define SLIST_ADD(T, _slist_list, _slist_data, _slist_result)               \
    do {                                                                    \
        SList_##T _slist_add = _slist_list;                                 \
        _slist_result = true;                                               \
                                                                            \
        SList_##T##_Node *_slist_new_node =                                 \
                malloc(sizeof *_slist_new_node);                            \
                                                                            \
        if(_slist_new_node) {                                               \
            _slist_result = true;                                           \
                                                                            \
            _slist_new_node->data = (_slist_data);                          \
            _slist_new_node->next = NULL;                                   \
            if(_slist_add.first) {                                          \
                SList_##T##_Node *_slist_i = _slist_add.first;              \
                for(; _slist_i->next != NULL; _slist_i = _slist_i->next);   \
                /* printf("i: %p\n", (void *)i); */                         \
                _slist_i->next = _slist_new_node;                           \
            } else {                                                        \
                _slist_add.first = _slist_new_node;                         \
            }                                                               \
        } else {                                                            \
            _slist_result = false;                                          \
        }                                                                   \
                                                                            \
        _slist_list = _slist_add;                                           \
    } while(0)

//Adds an item before pos to the list
#define SLIST_INSERT(T, _slist_list, _slist_before_pos, _slist_data, _slist_result) \
    do {                                                                \
        SList_##T _slist_insert = _slist_insert;                        \
                                                                        \
        SList_##T##_Node *_slist_pos = (_slist_before_pos);             \
                                                                        \
        _slist_result = false;                                          \
                                                                        \
        if(_slist_pos == _slist_insert.first) {                         \
            SList_##T##_Node *_slist_new_node =                         \
                    malloc(sizeof *_slist_new_node);                    \
            if(_slist_new_node) {                                       \
                _slist_insert.first = _slist_new_node;                  \
                _slist_new_node->data = (_slist_data);                  \
                _slist_new_node->next = _slist_pos;                     \
                                                                        \
                _slist_result = true;                                   \
            }                                                           \
        } else {                                                        \
            SList_##T##_Node *_slist_i = _slist_insert.first;           \
            for(; _slist_i->next != NULL; _slist_i = _slist_i->next) {  \
                if(_slist_i->next == _slist_pos) {                      \
                    SList_##T##_Node *_slist_new_node =                 \
                            malloc(sizeof *_slist_new_node);            \
                    if(!_slist_new_node) {                              \
                        /* _slist_result = false; */                    \
                        break;                                          \
                    }                                                   \
                                                                        \
                    _slist_i->next = _slist_new_node;                   \
                    _slist_new_node->data = (_slist_data);              \
                    _slist_new_node->next = _slist_pos;                 \
                                                                        \
                    _slist_result = true;                               \
                    break;                                              \
                }                                                       \
            }                                                           \
        }                                                               \
                                                                        \
        _slist_list = _slist_insert;                                    \
    } while(0)

/*
#define SLIST_ADD_FRONT(T, _slist_list, _slist_data, _slist_result) \
        SLIST_INSERT(T, _slist_list.
*/

#endif // SLIST_H_INCLUDED
