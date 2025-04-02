/*Topological sorting.*/

#include <stdio.h>
#define MAX 20

typedef struct{
  int data[MAX];
  int top;
} STACK;

void push(STACK *s, int n){
  s->data[++s->top] = n; 
}

int pop(STACK *s){
  return s->data[s->top--];
}

void init(STACK *s){
  s->top = -1;
}

int isEmpty(STACK *s){
  return (s->top == -1);
}

void topologicalSort(int m[MAX][MAX], int n){
  int i, j, v, w;
  int visited[MAX] = {0};
  int indeg[MAX];

  for(i = 0; i < n; i++)
    indeg[i] = 0;

  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      indeg[i] += m[j][i];

  STACK s;
  init(&s);

  while (1) {
    for(v = 0; v < n; v++){
      if(!visited[v] && indeg[v] == 0){
	visited[v] = 1;
	push(&s, v);
	printf("v%d ", v + 1);
      }
    }
        
    if(isEmpty(&s))
      break;

    v = pop(&s);

    for(w = 0; w < n; w++){
      if(m[v][w] == 1)
	indeg[w]--;
    }
  }
}

void main(){
  int m[MAX][MAX];
  int i,j, n;
  printf("How many vertices: ");
  scanf("%d", &n);
  for(i=0;i<n;i++)
    for(j=0;j<n;j++){
      m[i][j]=0;
      if(i!=j){
	printf("Is there an edge between %d->%d (1/0)? ",i+1,j+1);
	scanf("%d",&m[i][j]);
      }
    }

  topologicalSort(m,n);
  printf("\n");
}
