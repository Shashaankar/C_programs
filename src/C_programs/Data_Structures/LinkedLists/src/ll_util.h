#include<stdio.h>
#include <stdlib.h>

#if !defined(LL_UTIL)
#define LL_UTIL
#define DLL_NODE_SIZE = sizeof(dll_node_s)

typedef struct dll_node {
    int key;
    int val;
    struct dll_node *next;
    struct dll_node *prev;
} dll_node_s;


#define push_dll(rootp, key, val) _insert_dll_node((rootp), (key), (val));

#endif
