#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int calculateTime(int** field, int N, int M, int inventory_block, int target_height);

int main() {
    int N, M, inventory_block;
    scanf("%d %d %d", &N, &M, &inventory_block);

    int min = 256, max = 0, num;

    int** field = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        int* arr_element = (int*)malloc(M * sizeof(int));
        field[i] = arr_element;

        for (int j = 0; j < M; j++) {
            scanf("%d", &num);
            field[i][j] = num;
            if (num > max) {
                max = num;
            }
            if (num < min) {
                min = num;
            }
        }
    }

    int min_work_time = INT_MAX;
    int highest_height = -1;
    int* time_per_height = (int*)malloc((max + 1) * sizeof(int));
    for (int i = max; i >= min; i--) {
        time_per_height[i] = calculateTime(field, N, M, inventory_block, i);

        if (time_per_height[i] < min_work_time) {
            min_work_time = time_per_height[i];
            highest_height = i;
        }
    }

    printf("%d %d", min_work_time, highest_height);

    return 0;
}

int calculateTime(int** field, int N, int M, int inventory_block, int target_height) {
    int work_time = 0, gap = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            gap = target_height - field[i][j];
            if (gap > 0) { // 땅을 채워야함
                work_time += gap;
                inventory_block -= gap;
            } else if (gap < 0) { // 땅을 파야함
                work_time += 2 * (-1 * gap);
                inventory_block += (-1 * gap);
            }
        }
    }

    if (inventory_block < 0) {
        work_time = INT_MAX;
    }

    return work_time;
}