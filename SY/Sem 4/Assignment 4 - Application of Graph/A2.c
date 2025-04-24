/*Dijkstra.*/

#include <stdio.h>

#define INF -1
#define MAX 10

void createmat(int cost[MAX][MAX], int n){
    int i, j;
    printf("\nEnter the adjacency matrix (use %d for no direct path):\n", INF);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i == j) {
                cost[i][j] = 0;
            }else{
                printf("Cost from vertex %d to vertex %d: ", i + 1, j + 1);
                scanf("%d", &cost[i][j]);
            }
        }
    }
}

void dijkstra(int cost[MAX][MAX], int start, int n){
    int dist[MAX], visited[MAX] = {0};
    int i, u = 0, w, count, min;

    for(i = 0; i < n; i++){
        dist[i] = cost[start][i];
    }

    dist[start] = 0;
    visited[start] = 1;
    count = 1;

    while(count < n){
        min = 999999; // Using a large number for comparison
        u = -1;

        // Find the unvisited vertex with the smallest known distance
        for(i = 0; i < n; i++){
            if (!visited[i] && dist[i] != INF && dist[i] < min){
                min = dist[i];
                u = i;
            }
        }

        if(u == -1) break; // No reachable unvisited vertex left

        visited[u] = 1;

        for(w = 0; w < n; w++){
            if(!visited[w] && cost[u][w] != INF){
                if(dist[w] == INF || dist[u] + cost[u][w] < dist[w]){
                    dist[w] = dist[u] + cost[u][w];
                }
            }
        }

        count++;
    }

    printf("\nShortest distances from vertex %d:\n", start + 1);
    for(i = 0; i < n; i++){
        if(dist[i] == INF)
            printf("Vertex %d: Unreachable\n", i + 1);
        else
            printf("Vertex %d: %d\n", i + 1, dist[i]);
    }
}

int main(){
    int cost[MAX][MAX], n, source;

    do{
        printf("Enter the number of vertices (1 to %d): ", MAX);
        scanf("%d", &n);
    }while (n < 1 || n > MAX);

    createmat(cost, n);

    do{
        printf("\nEnter the source vertex (1 to %d): ", n);
        scanf("%d", &source);
    }while (source < 1 || source > n);
    dijkstra(cost, source - 1, n);
    return 0;
}
