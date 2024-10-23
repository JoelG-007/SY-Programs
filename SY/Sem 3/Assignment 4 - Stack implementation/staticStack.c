/*  a) Implement a stack library (ststack.h) of integers using a static implementation of the stack 
    and implementing the above six operations. Write a driver program that includes stack library 
    and calls different stack operations. */

#include<stdio.h>
#include<stdlib.h>
#include"ststack.h"
void main(){
	int n,choice,i;
  	STACK s;
  	inistack(&s);
	do{
      		printf("\n\t1.PUSH\n\t2.POP\n\t3.PEEK\n\t4.EXIT\n");
      		printf("\nEnter operation to be performed -  ");
      		scanf("%d",&choice);
      		switch(choice){
		case 1:if(isfull(&s))
            			printf("\n\n----------------------\nSTACK OVERFLOW\n----------------------\n");
          	       else{
	      			printf("Enter the element (to be PUSH'd): \n");
	      			scanf("%d",&n);
	      			push(&s,n);
	    	       }
		       break;
		case 2:if(isempty(&s))
            			printf("\n\n----------------------\nSTACK UNDERFLOW\n----------------------\n");
          	       else
            			printf("\n\n----------------------\nPOP'd elements is %d\n------------------",pop(&s));
          	       break;
		case 3:if(isempty(&s))
            			printf("\n\n----------------------\nSTACK UNDERFLOW\n----------------------\n");
          	       else
            			printf("\n\n----------------------\nThe topmost element is %d\n----------------------",peek(&s));
                       break;
		}
	}while(choice!=4);
}                                                                                                                                                           
          


