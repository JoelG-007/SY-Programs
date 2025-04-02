#include <stdio.h>
#define MAX 20

void dfs(int m[MAX][MAX], int n, int v, int visited[MAX]){
    int w;
    visited[v] = 1;
    printf("v%d ", v + 1);

    for (w = 0; w < n; w++){
        if (m[v][w] == 1 && visited[w] == 0)
            dfs(m, n, w, visited);
    }
}

int main() {
    int m[MAX][MAX], n, v, i, j;
    int visited[MAX] = {0};

    printf("How many vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++){
            if (i == j) {
                m[i][j] = 0;
            }else{
                printf("Is there an edge between %d->%d (1/0)? ", i + 1, j + 1);
                scanf("%d", &m[i][j]);
            }
        }
    }

    printf("\nThe DFS traversal is: \n");
    dfs(m, n, 0, visited);

    return 0;
}
