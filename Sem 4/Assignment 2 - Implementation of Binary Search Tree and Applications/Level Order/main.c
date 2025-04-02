#include<stdio.h>
#include<stdlib.h>
#include "btree.h"

void main(){
  NODE *root=NULL;
  root=createBST(root);
  levelorder(root);
}
 
