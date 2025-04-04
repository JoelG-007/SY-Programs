/*
	Write a C program that accepts the vertices and edges of a graph. Create adjacency list. 
	Implement functions to print indegree, outdegree and total degree of all vertex of graph. 
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
  int vertex;
  struct NODE *next;
}NODE;

NODE *list[10];

void createAdjList(int m[10][10], int n){
  int i,j;
  NODE *temp,*newnode;
  for(i=0;i<n;i++)
    list[i]=NULL;

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(m[i][j]==1){
	newnode=(NODE *)malloc(sizeof(NODE));
	newnode->vertex=j+1;
	newnode->next=NULL;

	if(list[i]==NULL)
	  list[i]=newnode;
	else{
	  temp=list[i];
	  while(temp->next!=NULL)
	    temp=temp->next;
	  temp->next=newnode;
	}
      }
    }
  }
}

void display(int n){
  int i;
  NODE *temp;
  printf("Adjacency List - \n");
  for(i=0;i<n;i++){
    printf("Vertex %d-> ",i+1);
    temp=list[i];
    while(temp!=NULL){
      printf("%d-> ",temp->vertex);
      temp=temp->next;
    }
    printf("NULL\n");
  }
}

void degree(int m[10][10], int n){
  int indeg[10]={0}, outdeg[10]={0},i,j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(m[i][j]==1){
	outdeg[i]++;
	indeg[j]++;
      }
    }
  }
  printf("\n\nVERTEX INDEGREE OUTDEGREE TOTAL DEGREE\n");
  for(i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\n",i+1,indeg[i],outdeg[i],indeg[i]+outdeg[i]);
  }
}

int main(){
  int m[10][10],n,i,j;
  printf("Enter the number of vertices - ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
    for(j=0;j<n;j++){
      m[i][j]=0;
      if(i!=j){
	printf("Is there an edge between %d->%d (1/0)? ",i+1,j+1);
	scanf("%d",&m[i][j]);
      }
    }
  createAdjList(m, n);
  display(n);
  degree(m, n);
}
