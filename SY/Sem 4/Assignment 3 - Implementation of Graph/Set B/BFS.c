#include <stdio.h>
#define MAX 20

typedef struct{
    int data[MAX];
    int front, rear;
} QUEUE;

void initq(QUEUE *q){
    q->front = q->rear = -1;
}

void enqueue(QUEUE *q, int n){
    q->data[++q->rear] = n;
}

int dequeue(QUEUE *q){
    return q->data[++q->front];
}

int isEmpty(QUEUE *q){
    return (q->rear == q->front);
}

void bfs(int m[MAX][MAX], int n){
  int visited[MAX] = {0}, w;
    QUEUE q;
    initq(&q);

    printf("\nThe BFS traversal is: \n");
    int v = 0;
    visited[v] = 1;
    enqueue(&q, v);

    while (!isEmpty(&q)) {
        v = dequeue(&q);
        printf("v%d ", v + 1);

        for (w = 0; w < n; w++) {
            if ((m[v][w] == 1) && (visited[w] == 0)){
                enqueue(&q, w);
                visited[w] = 1;
            }
        }
    }
    printf("\n");
}

int main(){
    int m[MAX][MAX], n, i, j;

    printf("How many vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            m[i][j] = 0;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i != j) {
                printf("Is there an edge between %d -> %d (1/0)? ", i + 1, j + 1);
                scanf("%d", &m[i][j]);
            }
        }
    }

    bfs(m, n);

    return 0;
}
