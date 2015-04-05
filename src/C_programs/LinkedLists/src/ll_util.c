#include "ll_util.h"


void* SRK_ALLOC(int size) {

    void *temp=NULL;
    temp  = malloc(size);

    if(!temp) {
        printf("\n malloc failed");
        return NULL;
    }

    return temp;
}


dll_node_s* _create_dll_node(int size) {
    dll_node_s *node=NULL;

    node = (dll_node_s *)SRK_ALLOC(size);
    if (!node) {
        printf("node allocation failed\n");
        exit(-1);
    }

    return node;
}

/** Create and Insert dll node and the end */
void _insert_dll_node_last(dll_node_s **rootp, int key, int val) {

    if (!rootp) {
        printf("_insert_dll: invalid address \n");
        return;
    }


    if (!*rootp) {
        printf("_insert_dll: root empty, insert first node \n");
        *rootp = _create_dll_node(sizeof(dll_node_s));
        (*rootp)->key = key;
        (*rootp)->val = val;
        (*rootp)->next = NULL;
        (*rootp)->prev = NULL;
    } else {
        /** create a node and insert, then update pointers accordingly */
        dll_node_s *new_node = NULL, *temp=NULL;
        new_node = _create_dll_node(sizeof(dll_node_s));
        new_node->key = key;
        new_node->val = val;
        new_node->next = NULL;

        temp = *rootp;

        /** Loop until last node */
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->prev = temp;
        printf("_insert_dll: key:%d, val:%d\n", new_node->key, new_node->val);
    }
}



/** print dll_list of nodes */

void _print_dll_nodes(dll_node_s **rootp) {

    dll_node_s *temp;

    if (!rootp || !*rootp) {
        printf("_print_dll: dll list empty \n");
        return;
    }
    temp = *rootp;

    while (temp) {
        printf("_print_dll: key=%d, val=%d\n", temp->key, temp->val);
        temp = temp->next;
    }
}


/** Free dll nodes */
void _free_dll_nodes(dll_node_s **rootp) {

    dll_node_s *temp=NULL;
    if (!rootp || !*rootp) {
        printf("_free_dll: dll list is empty \n");
        return;
    }

   while (*rootp) {
       temp = (*rootp)->next;
       printf("_free_dll: key:%d, val:%d\n", (*rootp)->key, (*rootp)->val);
       free(*rootp);
       *rootp = temp;
   }

}
