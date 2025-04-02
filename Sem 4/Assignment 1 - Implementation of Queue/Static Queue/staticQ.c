#include<stdio.h>
#include<stdlib.h>
#include"stQ.h"
void main(){
  int n,choice;
  Queue q;
  initQ(&q);
  do{
    printf("\n\t1.Enqueue\n\t2.Dequeue\n\t3.PEEK\n\t4.Display\n\t5.Exit");
    printf("\nEnter operation to be performed -  ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
      if(isfull(&q))
	printf("\n\n\nQUEUE OVERFLOW, QUEUE is full.\n\n");
      else{
	printf("Enter the element (to be Enqueue'd): \n");
	scanf("%d",&n);
	enqueue(&q,n);
      }
      break;
    case 2:
      if(isempty(&q))
	printf("\n\nQUEUE UNDERFLOW, QUEUE is empty.\n\n");
      else
	printf("\n\nDequeue'd elements is %d\n",dequeue(&q));
      break;
    case 3:
      if(isempty(&q))
	printf("\n\nQUEUE UNDERFLOW, QUEUE is empty.\n\n");
      else
	printf("\n\nThe foremost element is %d\n",peek(&q));
      break;
    case 4:
      if(isempty(&q))
	printf("\n\nQUEUE UNDERFLOW, QUEUE is empty.\n\n");
      else
	display(&q);
      break;
    case 5:
      printf("\n\nExiting...\n");
      break;
    default:
      printf("\n\nOption not available...");
    }
  }while(choice!=5);
}                                                                                                                                                           
          


