#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

int map[MAX][MAX] = {0};
int arr[MAX] = {0};

bool eraseNode(int N, int target);

int main() {
    int N, M;
    int u, v;
    scanf("%d %d", &N, &M);

    int cnt = 0;

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        map[u][v] = 1;
        map[v][u] = 1;
        arr[u]++;
        arr[v]++;
    }

    for (int i = 1; i <= N; i++) {
        if (arr[i] == 0) {
            cnt++;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (eraseNode(N, i)) {
            cnt++;
        }
    }
    printf("%d", cnt);

    return 0;
}

bool eraseNode(int N, int target) {
    bool erased = false;

    for (int i = 1; i <= N; i++) {
        if (map[target][i] == 1) {
            erased = true;
            map[target][i] = 0;
            map[i][target] = 0;
            eraseNode(N, i);
        }
    }

    return erased;
}
