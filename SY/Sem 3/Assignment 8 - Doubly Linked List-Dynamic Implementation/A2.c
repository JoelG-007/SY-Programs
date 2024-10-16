/*  b) Implement a list library (doublylist.h) for a doubly linked list. Create a linked list, reverse 
    it and display reversed linked list.*/

#include <stdio.h>
#include <stdlib.h>
#include "doublylist.h"

void main() {
    NODE *head;
    head = (NODE *) malloc(sizeof(NODE));
    head -> next = NULL;
    head -> prev = NULL;

    createlist(head);
    printf("\n\tOriginal List:\n");
    display(head);

    reverseList(head);
    printf("\tReversed List:\n");
    display(head);
}
