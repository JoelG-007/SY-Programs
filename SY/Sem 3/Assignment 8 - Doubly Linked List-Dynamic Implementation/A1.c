/*	a) Implement a list library (doublylist.h) for a doubly linked list with the above four 
	operations. Write a menu driven driver program to call the operations append, insert, delete 
	specific node, delete at position, search, display.*/

#include <stdio.h>
#include <stdlib.h>
#include "doublylist.h"

void main() {
    	NODE *head;
    	head = (NODE *) malloc(sizeof(NODE));
    	head -> next = NULL;
    	head -> prev = NULL;
    	int choice, num, pos;
    	createlist(head);
    	do{
        	printf("\n\t1. INSERT \n\t2. DELETE BY NUMBER\n\t3. DELETE BY POSITION\n\t4. SEARCH\n\t5. DISPLAY\n\t6. APPEND\n\t7. EXIT\n");
        	printf("\nEnter your choice: ");
        	scanf("%d", &choice);
        	switch(choice){
            		case 1 :printf("\nEnter the element and position: ");
                		printf("\nElement - ");
				scanf("%d",&num);
				printf("\nPosition - ");
                    		scanf("%d",&pos);
                		insert(head, num, pos);
                		display(head);
               	 		break;
            		case 2 :printf("\nEnter the element: ");
                		scanf("%d",&num);
                		deleteByValue(head, num);
                		display(head);
                		break;
            		case 3 :printf("\nEnter the position: ");
                		scanf("%d", &pos);
                		deleteByPos(head, pos);
                		display(head);
                		break;
            		case 4 :printf("\nEnter the element to be searched: ");
                		scanf("%d",&num);
                		pos = search(head, num);
                		if(pos == -1)
                    			printf("\nElement not found.");
                		else
                    			printf("\nElement found at position %d", pos + 1);
                		break;
            		case 5 :printf("\nList Item:\n");
                		display(head);
                		break;
            		case 6 :printf("\nEnter a number to append: ");
                		scanf("%d", &num);
                		append(head, num);
                		printf("\nNumber appended:\n");
                		display(head);
                		break;
            		case 7 :printf("Exiting...");
                		break;
            		default:
                		printf("Invalid Choice!!");
                		break;
        	}
    	} while(choice != 7);
}
