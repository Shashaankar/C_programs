#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
    int key;
    int value;
    struct tnode *left;
    struct tnode *right;
}tnode;

void* SRK_ALLOC(int size) {

    void *temp=NULL;
    temp  = malloc(size);

    if(!temp) {
         printf("\n malloc failed");
         return NULL;
    }

    return temp;
}


#define TNODE_SIZE (sizeof(struct tnode))

tnode *root = NULL;


void _tree_insert_left(tnode *rootp, int key, int value) {

    if (!rootp || rootp->left) {
        printf("Invalid root or left pointer \n");
        return;
    }

    rootp->left = (struct tnode *)SRK_ALLOC(TNODE_SIZE);

    rootp->left->key = key;
    rootp->left->value = value;

}


void _tree_insert_right(struct tnode *rootp, int key, int value) {

    if (!rootp || rootp->right) {
        printf("Invalid root or right pointer \n");
        return;
    }

    rootp->right = (struct tnode *)SRK_ALLOC(TNODE_SIZE);

    rootp->right->key = key;
    rootp->right->value = value;

}

int _full_btree_recursive(tnode *rootp) {
    int res=0;

    if (!rootp) {
        return;
    }

    if (rootp->left) {
        if (rootp->right) {
            res  = _full_btree_recursive(rootp->left);
        } else {
            return -1;
        }
    }

    if (rootp->right) {
        if (rootp->left) {
            res  = _full_btree_recursive(rootp->right);
        } else {
            return -1;
        }
    }

    return res;
}

void _print_tree(tnode *rootp) {

    if (!rootp)  {
        printf("_print_tr: Empty tree\n");
    }


}

void _free_tnode(tnode *rootp) {

    if (!rootp) {
        return;
    }


    if (rootp->left) {
        _free_tnode(rootp->left);
    }
    if (rootp->right) {
        _free_tnode(rootp->right);
    }

    /** leaf node */
    if (!rootp->left && !rootp->right) {
        printf("_free_tnode: key: %d, value: %d\n", rootp->key, root->value);
        free(rootp);
    }            

    /** free the node */
    if (rootp->left || rootp->right) {
        printf("_free_tnode: key: %d, value: %d\n", rootp->key, rootp->value);
        free(rootp);
    }

}

void _check_full_binary_tree() {

    tnode *rootp = NULL;
    int out = 0;
    root = (struct tnode *)SRK_ALLOC(TNODE_SIZE);
    root->key = 0;
    root->value = 0;

    _tree_insert_left(root, 5, 0);
    _tree_insert_right(root, 6, 0);
    _tree_insert_right(root->right, 7, 0);


    /** logic to check for full binary tree */
    rootp = root;
    if(!rootp) {
        printf("Tree is empty \n");
    }

    out = _full_btree_recursive(rootp);

    printf("output = %d\n", out);

    _free_tnode(root);

}


void main() {

    _check_full_binary_tree();
}



