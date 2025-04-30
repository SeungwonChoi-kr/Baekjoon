#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    char** map = (char**)malloc(N * 5 * sizeof(char*));
    for (int i = 0; i < N * 5; i++) {
        char* row = (char*)malloc(N * 5 * sizeof(char));
        for (int j = 0; j < N * 5; j++) {
            row[j] = '@';
        }
        map[i] = row;
    }

    for (int i = N; i < N * 5; i++) {
        for (int j = N; j < N + N; j++) {
            map[i][j] = ' ';
        }
    }

    for (int i = 0; i < N * 4; i++) {
        for (int j = N * 3; j < N * 4; j++) {
            map[i][j] = ' ';
        }
    }

    for (int i = 0; i < N * 5; i++) {
        for (int j = 0; j < N * 5; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}