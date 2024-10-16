/*  b) Implement a stack library (dystack.h) of integers using a dynamic (linked list) 
    implementation of the stack and implementing the above five operations. Write a driver 
    program that includes stack library and calls different stack operations. */

#include <stdio.h>
#include <stdlib.h>
#include "dynStack.h"
void main(){
        int n,choice;
        do{
                printf("\n\t1.PUSH\n\t2.POP\n\t3.PEEK\n\t4.EXIT\n");
                printf("\nEnter operation to be performed -  ");
                scanf("%d",&choice);
                switch(choice){
                case 1:printf("Enter the element (to be PUSH'd): \n");
                       scanf("%d",&n);
                       push(n);
                       break;
                case 2:if(isempty())
                                printf("\n\n----------------------\nSTACK UNDERFLOW\n----------------------\n");
                       else
                                printf("\n\n----------------------\nPOP'd elements is %d\n------------------",pop(n));
                       break;
                case 3:if(isempty())
                                printf("\n\n----------------------\nSTACK UNDERFLOW\n----------------------\n");
                       else
                                printf("\n\n----------------------\nThe topmost element is %d\n----------------------",peek(n));
                       break;
                }
        }while(choice!=4);
}                                                                                                                                      

