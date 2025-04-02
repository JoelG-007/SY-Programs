#include<stdio.h>
#include<stdlib.h>
#include "btree.h"

void main(){
  int num, choice;
  NODE *root=NULL, *pos;
  do{
    printf("\n\t1.Create tree\n\t2.PreOrder\n\t3.InOrder\n\t4.PostOrder\n\t5.Search\n\t6.EXIT");
    printf("\nEnter operation to be performed -  ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
      root=createBST(root);
      break;
    case 2:
      preorder(root);
      break;
    case 3:
      inorder(root);
      break;
    case 4:
      postorder(root);
      break;
    case 5:
      printf("Enter number to search - ");
      scanf("%d", &num);
      pos=search(root, num);
      if(pos!=NULL)
	printf("Node Found");
      else
      printf("Node not Found");
      break;
    case 6:
      printf("\n----------EXITING----------\n");
      break;
    default:
      printf("\n\nOption not available...\n\n");
    }
  }while(choice!=6);
}   

