#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K, block, best;
    scanf("%d %d", &N, &K);
    block = K - 1;

    int* input = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
    }

    int** map = (int**)malloc(K * sizeof(int*));
    for (int i = 0; i < K; i++) {
        int* line = (int*)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            line[j] = -5000;
        }
        map[i] = line;
    }
    for (int j = 0; j < N; j++) {
        map[0][j] = input[j];
    }

    for (int i = 1; i < K; i++) {
        best = map[i - 1][i - 1];

        for (int j = i; j < N; j++) {
            if (best < map[i - 1][j - 1]) {
                best = map[i - 1][j - 1];
            }

            map[i][j] = input[j] - i + best;
        }
    }

    // for (int i = 0; i < K; i++) {
    //     for (int j = 0; j < N; j++) {
    //         if (map[i][j] == -5000)
    //             printf("  (%d)\t", input[j] - i);
    //         else
    //             printf("%d(%d)\t", map[i][j], input[j] - i);
    //     }
    //     printf("\n");
    // }

    best = -1300000000;
    for (int j = K - 1; j < N; j++) {
        if (best < map[K - 1][j]) {
            best = map[K - 1][j];
        }
    }
    printf("%d", best);

    return 0;
}