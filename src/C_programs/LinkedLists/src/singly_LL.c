#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int x; /** X- coordinate */
    int y; /** Y - coordinate */
    struct node *next;
}node;

#define NODE_SIZE sizeof(struct node)

struct node *head=NULL;
void* SRK_ALLOC(int size) {

    void *temp=NULL;
    temp  = malloc(size);

    if(!temp) {
        printf("\n malloc failed");
        return NULL;
    }

    return temp;
}

void* _create_singly_LL(struct node *LLhead, int num, int size) {

    int i=0, ret=0;
    struct node *last_temp, *temp, *head;
    if (LLhead || num < 0 || size <=0 ) {
        printf("\n LL head is not Null");
        return NULL;
    }

    for (i=0; i < num; i++) {
        temp = (struct node *)SRK_ALLOC(size);
        if (!temp) {
            return NULL;
        }

        if (!i) {
            /** First element next to head */
            head = (struct node *)temp;
            temp->next = NULL;
            last_temp = temp;
            LLhead = head;
        } else {

            last_temp->next = (struct node *)temp;
            temp->next = NULL;
            last_temp = temp;
        }

        /** Fill in the temp values */
        temp->x=i;
        temp->y=i;
    }
    printf("\n Singly LL is created ");
    return LLhead;

}

void _print_singly_LL(struct node *head, int num) {

    int i=0;
    struct node *temp = head;

    if (!temp) {
        printf("_print_LL: LL is empty\n");
        return;
    }

    for (i=0; i < num; i++) {

        printf("_print_LL: node%d: x=%d, y=%d\n", (i+1), temp->x, temp->y);
        temp = temp->next;
    }
}

void _print_full_LL(struct node *headp) {

    if(!headp) {
        printf("_print_full_LL: empty list \n");
        return;
    }

    while(headp) {
        printf("_print_full_LL: %d, %d\n", headp->x, headp->y);
        headp = headp->next;
    }

}

void _free_singly_LL(struct node *headp) {

    struct node *head = headp;

    if (!head) {
        printf("free: Invalid head pointer \n");
        return;
    }

    if(!head->next) {
        printf("_free_LL: reached end of LL_free\n");
    } else {
        _free_singly_LL(head->next);
    }

    printf("_free_LL: free node: %d, %d\n", head->x, head->y);
    free(head);
    return;
}

void _insert_last_singly_LL(int x, int y) {

    struct node *temp=NULL, *nodep;
    temp = head;

    nodep = (struct node *)SRK_ALLOC(sizeof(struct node));
    nodep->x = x;
    nodep->y = y;

    if(!head) {
        // first node to be created
        head = nodep;
        head->next = NULL;
        printf("_insert_LL: first node created values: %d, %d\n", head->x, head->y);
        return;
    }

    // loop through until last node
    while(temp->next) {
        temp = temp->next;
    }

    temp->next = nodep;
    nodep->next = NULL;

    printf("_insert_node: Inserted node with values: %d, %d\n", nodep->x, nodep->y);

}

void _remove_middle_points() {

    /** logic to remove middle elements */
    struct node *temp=NULL, *delete_node=NULL;

    /** Insert and print nodes */
    _insert_last_singly_LL(0, 10);
    _insert_last_singly_LL(1, 10);
    _insert_last_singly_LL(5, 10);
    _insert_last_singly_LL(7, 10);
    _insert_last_singly_LL(7, 5);
    _insert_last_singly_LL(20, 5);
    _insert_last_singly_LL(40, 5);

    _print_full_LL(head);


    temp = head;
    while (temp) {

        printf("In while loop %d, %d\n", temp->x, temp->y);

        /** Only if there are three or more nodes in the LL */
        if (temp && temp->next && temp->next->next) {

                /** horizontal lines */
            if ((temp->y == (temp->next)->y) && (temp->y == ((temp->next)->next)->y) ||
                    /** Vertical lines */
                   (temp->x == (temp->next)->x) && (temp->x == ((temp->next)->next)->x) ) {
                /** delete the temp->next node */
                delete_node = temp->next;
                temp->next = delete_node->next;
                printf("_remove_middle: deleting %d, %d\n", delete_node->x, delete_node->y);
                free(delete_node);
            } else {
                /** advancing to next node */
                    temp = temp->next;
            }
        } else {
            break;
        }

    }

    printf("_remove_middle: After deleting middle points \n");

    _print_full_LL(head);

    _free_singly_LL(head);
}

void main() {

    int size=sizeof(struct node), num=5;
    int error=0;

    /** 
    head = (struct node *)_create_singly_LL(head, num, size);
    if (!head) {
        printf("\n Error in creating Singly LL");
    }

    _print_singly_LL(head, num);

    _free_singly_LL(head);

    **/

    _remove_middle_points();

}
