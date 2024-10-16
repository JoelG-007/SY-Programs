/*	b) Implement a list library (singlylist.h) for a singly linked list. Create a linked list, reverse it 
	and display reversed linked list. */

#include<stdio.h>
#include<stdlib.h>
#include"singlylist.h" 
void main(){
 	NODE *head1,*head2,*head3;
 	int choice,n,pos;
 	head1=(NODE *)malloc(sizeof(NODE));
 	head1->next=NULL;
 	head2=(NODE *)malloc(sizeof(NODE));
 	head2->next=NULL;
 	head3=(NODE *)malloc(sizeof(NODE));
 	head3->next=NULL;

	do{
  		printf("\n\t1.Create \n\t2.Reverse \n\t3.Exit");
 		printf("\n Enter your choice:");
 		scanf("%d",&choice);
		switch(choice){
  			case 1 :createList(head1);
        			break;
  			case 2 :rev(head1);
                    display(head1);
                    break;
    			}
  	}while(choice!=3);
}
