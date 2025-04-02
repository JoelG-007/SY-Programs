#include<stdio.h>
#include<stdlib.h>
#include "btree.h"

void main(){
  NODE *root=NULL;
  root=createBST(root);
  printf("\nNumber of nodes in the tree - %d\n" ,countNodes(root));
  printf("\nNumber of Leaf in the tree - %d\n", countLeafs(root));
}
 
