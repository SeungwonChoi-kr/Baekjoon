#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct COOR {
    int row;
    int col;
} COOR;

int main() {
    int N, width;
    scanf("%d", &N);
    width = (N / 3) * 6 - 1;

    char** map = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        char* line = (char*)malloc((width + 1) * sizeof(char));
        for (int j = 0; j < width; j++) {
            line[j] = ' ';
        }

        map[i] = line;
    }

    int** world = (int**)malloc((N / 3) * sizeof(int*));
    for (int i = 0; i < N / 3; i++) {
        int* world_line = (int*)calloc(N / 3, sizeof(int));
        world[i] = world_line;
    }

    for (int i = 0; i < N / 3; i++) {
        world[i][0] = 1;
    }

    for (int i = 1; i < N / 3; i++) {
        for (int j = 1; j <= i; j++) {
            world[i][j] = world[i - 1][j - 1] + world[i - 1][j];
            world[i][j] %= 2;
        }
    }

    // for (int i = 0; i < N / 3; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         printf("%d ", world[i][j]);
    //     }
    //     printf("\n");
    // }

    COOR*** coor_world = (COOR***)malloc((N / 3) * sizeof(COOR**));
    for (int i = 0; i < N / 3; i++) {
        COOR** coor_line = (COOR**)malloc((i + 1) * sizeof(COOR*));
        for (int j = 0; j < i + 1; j++) {
            COOR* coor = (COOR*)malloc(sizeof(COOR));
            coor_line[j] = coor;
        }
        coor_world[i] = coor_line;
    }
    coor_world[0][0]->row = 0;
    coor_world[0][0]->col = width / 2;

    for (int i = 1; i < N / 3; i++) {
        for (int j = 0; j < i; j++) {
            coor_world[i][j]->row = coor_world[i - 1][j]->row + 3;
            coor_world[i][j]->col = coor_world[i - 1][j]->col - 3;
        }
        coor_world[i][i]->row = coor_world[i - 1][i - 1]->row + 3;
        coor_world[i][i]->col = coor_world[i - 1][i - 1]->col + 3;
    }

    // for (int i = 0; i < N / 3; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         printf("(%d, %d) ", coor_world[i][j]->row, coor_world[i][j]->col);
    //     }
    //     printf("\n");
    // }

    int row, col;
    for (int i = 0; i < N / 3; i++) {
        for (int j = 0; j <= i; j++) {
            if (world[i][j] == 1) {
                row = coor_world[i][j]->row;
                col = coor_world[i][j]->col;

                map[row][col] = '*';
                map[row + 1][col - 1] = '*';
                map[row + 1][col + 1] = '*';
                map[row + 2][col - 2] = '*';
                map[row + 2][col - 1] = '*';
                map[row + 2][col] = '*';
                map[row + 2][col + 1] = '*';
                map[row + 2][col + 2] = '*';
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}