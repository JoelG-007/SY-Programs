/*
	Write a C program that accepts the vertices and edges of a graph and stores it as an 
	adjacency matrix. Display the adjacency matrix. Implement functions to print indegree, 
	outdegree and total degree of all vertices of graph.
*/
#include<stdio.h>
#define MAX 10
void initialize(int n, int m[MAX][MAX]){
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++){
      m[i][j]=0;
      if(i!=j){
	printf("Is there an edge between %d->%d (1/0)? ",i+1,j+1);
	scanf("%d",&m[i][j]);
      }
    }
}

void display(int n, int m[MAX][MAX]){
  int i,j;
  printf("Adjacency Matrix - \n");
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d",m[i][j]);
    }
    printf("\n");
  }
}

void printDegree(int n, int m[MAX][MAX]){
  int v,i,sumin,sumout;
  printf("\n\nVERTEX INDEGREE OUTDEGREE TOTAL DEGREE\n");
  for(v=0;v<n;v++){
    sumin=sumout=0;
    for(i=0;i<n;i++){
      sumin=sumin+m[i][v];
      sumout=sumout+m[v][i];
    }
    printf("%d\t%d\t%d\t%d\n",v+1,sumin,sumout,sumin+sumout);
  }
}

int main(){
  int m[MAX][MAX];
  int n;
  printf("Enter the number of vertices - ");
  scanf("%d",&n);
  initialize(n,m);
  display(n,m);
  printDegree(n,m);
  return 0;
}
