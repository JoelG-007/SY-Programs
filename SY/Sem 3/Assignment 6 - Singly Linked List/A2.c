/*	b) Implement a list library (singlylist.h) for a singly linked list. Create a linked list, reverse it 
	and display reversed linked list. */

#include<stdio.h>
#include<stdlib.h>
#include"singlylist.h" 
void main(){
 	NODE *head1;
 	head1=(NODE *)malloc(sizeof(NODE));
 	head1->next=NULL;
  	createList(head1);
	printf("\n\tBefore reversing - ");
        display(head1);
	printf("\n\tAfter reversing  - ");
	rev(head1);
        display(head1);
}
