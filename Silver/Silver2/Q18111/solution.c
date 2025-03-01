#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y;
    int block_cnt;
    scanf("%d %d %d", &x, &y, &block_cnt);

    int** array = (int**)malloc(x * sizeof(int*));

    for (int i = 0; i < x; i++) {
        int* arr_element = (int*)malloc(y * sizeof(int));
        array[i] = arr_element;

        for (int j = 0; i < y; j++) {
            int num;
            scanf("%d", &num);

            array[i][j] = num;
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}