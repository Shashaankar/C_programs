#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int x; /** X- coordinate */
    int y; /** Y - coordinate */
    struct node *next;
}node;

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

    if (!head) {
        printf("\n LL is empty");
        return;
    }

    for (i=0; i < num; i++) {

        printf("\n x=%d, y=%d", head->x, head->y);
        head = head->next;
    }
}

void _free_singly_LL(struct node *head) {

    if (!head) {
        printf("\n Invalid head pointer ");
        return;
    }

    if(!head->next) {
        printf("\n reached end of LL");
    } else {
        _free_singly_LL(head->next);
    }

    free(head);
    return;
}

void main() {

    int size=sizeof(struct node), num=5;
    int error=0;

    head = (struct node *)_create_singly_LL(head, num, size);
    if (!head) {
        printf("\n Error in creating Singly LL");
    }

    _print_singly_LL(head, num);

    _free_singly_LL(head);


}
