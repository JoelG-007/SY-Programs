/*Dijkstra.*/

#include<stdio.h>
#define INF -1
#define MAX 20

void dijkstra(int n, int cost[MAX][MAX], int start){
    int dist[MAX], visited[MAX] = {0};
    int count = 1, min, next, i, j;

    for(i = 0; i < n; i++)
        dist[i] = cost[start][i];

    visited[start] = 1;
    dist[start] = 0;

    while(count < n){
        min = INF;
        next = -1;

        // Find the nearest unvisited vertex
        for(i = 0; i < n; i++)
            if(!visited[i] && dist[i] < min){
                min = dist[i];
                next = i;
            }

        if(next == -1) break; // No more reachable vertices

        visited[next] = 1;
        count++;

        for(i = 0; i < n; i++)
            if(!visited[i] && cost[next][i] != INF && dist[next] + cost[next][i] > dist[i])
                dist[i] = dist[next] + cost[next][i];
    }

    printf("\nShortest distances from vertex %d:\n", start + 1);
    for(i = 0; i < n; i++){
        if(dist[i] == INF)
            printf("To vertex %d: Unreachable\n", i + 1);
        else
            printf("To vertex %d: %d\n", i + 1, dist[i]);
    }
}

int main(){
    int n, cost[MAX][MAX], start, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix (use %d for no direct path):\n", INF);
    for(i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if(i == j)
                cost[i][j] = 0; // No cost for self-loops
            else{
                printf("Cost from vertex %d to vertex %d: ", i + 1, j + 1);
                scanf("%d", &cost[i][j]);
            }
        }
    }
    printf("\nEnter source Vertex - ");
    scanf("%d",&start);
    dijkstra(n, cost, start-1);
    /*
    for(i=0;i<n;i++){
      printf("Source - v%d\n",i+1);
      dijkstra(n, cost, i); //number of vertex, matrix, starting vertex
    }
    */
    return 0;
}
