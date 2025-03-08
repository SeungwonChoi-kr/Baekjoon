#include <stdio.h>
#include <string.h>
#define MAX 1001

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

void DFS(int N, int V);
void BFS(int N, int V);

int main() {
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);

    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    DFS(N, V);
    printf("\n");
    memset(visited, 0, sizeof(int) * (N + 1));
    BFS(N, V);

    return 0;
}

void DFS(int N, int V) {
    visited[V] = 1;
    printf("%d ", V);
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0 && graph[V][i] == 1) {
            DFS(N, i);
        }
    }
}

void BFS(int N, int V) {
    int rear = -1, front = -1, pop;
    visited[V] = 1;
    printf("%d ", V);
    queue[++rear] = V;

    while (front < rear) {
        pop = queue[++front];
        for (int i = 1; i <= N; i++) {
            if (visited[i] == 0 && graph[pop][i] == 1) {
                printf("%d ", i);
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}