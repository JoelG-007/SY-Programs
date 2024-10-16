/*	a) Implement a list library (singlylist.h) for a singly linked list with the above six operations. 
	Write a menu driven driver program to call the operations. */

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
  		printf("\n\t1.Create \n\t2.Insert \n\t3.Search \n\t4.Delete by Value \n\t5.Delete by Position \n\t6.Append \n\t7.Reverse\n\t8.Display \n\t9.Exit");
 		printf("\n\tEnter your choice: ");
 		scanf("%d",&choice);
		switch(choice){
  			case 1 :createList(head1);
        			break;
  			case 2 :printf("Enter the element and position:");
         			printf("\nElement - ");
					scanf("%d",&n);
					printf("\nPosition - ");
                    scanf("%d",&pos);
         			insert(head1,n,pos-1);
         			display(head1);
        			break;
  			case 3 :printf("Enter the element to be searched:");
         			scanf("%d",&n);
         			pos=search(head1,n);
         			if(pos==-1)
           				printf("Element not found");
         			else
           				printf("Element found at position %d",pos);
         			break;
  			case 4 :printf("Enter the element:");
         			scanf("%d",&n);
         			deleteByVal(head1,n);
         			display(head1);
         			break;
  			case 5 :printf("Enter the element:");
         			scanf("%d",&pos);
         			deleteByPos(head1,pos);
         			display(head1);
         			break;
			case 6 :printf("Enter element data - ");
					scanf("%d",&n);
					append(head1, n);
					display(head1);
					break;
			case 7 :rev(head1);
         			display(head1);
         			break; 
 			case 8 :display(head1);
         			break;
    			}
  	}while(choice!=9);
}
         
