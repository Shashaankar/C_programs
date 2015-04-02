#include<stdio.h>
#include <stdlib.h>
#include "tnode.h"

extern void* SRK_ALLOC(int size);
static tnode *root;
extern _print_inorder_tree(tnode *rootp);
extern _free_tnode(tnode *rootp);
extern _print_bst_range(tnode *rootp, int k1, int k2);

#define TNODE_SIZE sizeof(tnode)

tnode* _create_tnode() {

    tnode *node;
    node = SRK_ALLOC(TNODE_SIZE);

    if (!node) {
        printf("_cr_nd: failed\n");
        exit(0);
    }
    return node;
}


int _insert_node_bst(tnode *rootp, int node_key) {

    tnode *new_node = NULL;


    if (!rootp) {
        printf("_insert_bst: Empty BST tree \n");
        return;
    }


    /** BST insert logic */

    if (rootp->key > node_key) {
        /** left sub tree */
        if (rootp->left) {
            return _insert_node_bst(rootp->left, node_key);
        } else {
            new_node = _create_tnode();
            new_node->key = node_key;
            new_node->value = 0;
            rootp->left = new_node;
        }
    } else {
        /** right sub tree */
        if (rootp->right) {
            return _insert_node_bst(rootp->right, node_key);
        } else {
            new_node = _create_tnode();
            new_node->key = node_key;
            new_node->value = 0;
            rootp->right = new_node;
        }

    }

    return 0;
}

void main() {

    /** create a root node for BST */

    root = _create_tnode(TNODE_SIZE);
    root->key = 3;
    root->value = 0;

    _insert_node_bst(root, 1);
    _insert_node_bst(root, 4);
    _insert_node_bst(root, 2);


    _print_bst_range(root, 2, 10);
    _print_inorder_tree(root);

    _free_tnode(root);

}
