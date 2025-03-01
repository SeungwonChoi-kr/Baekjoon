#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergeSort(int* levels, int start, int end);
void merge(int* levels, int start, int middle, int end);

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0");
        return 0;
    }

    int start, end;
    int real_amount;
    int sum = 0;

    int* levels = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &levels[i]);
    }

    mergeSort(levels, 0, n - 1);

    real_amount = round((n * 3 / 10) / 2.0);

    start = real_amount;
    end = n - 1 - real_amount;

    for (int i = start; i <= end; i++) {
        sum += levels[i];
    }

    sum = round((float)sum / (float)(end - start + 1));
    printf("%d", sum);

    return 0;
}

void mergeSort(int* levels, int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;

        mergeSort(levels, start, middle);
        mergeSort(levels, middle + 1, end);

        merge(levels, start, middle, end);
    }
}

void merge(int* levels, int start, int middle, int end) {
    int i = start;
    int j = middle + 1;
    int loop = end - start + 1;
    int copy = 0;
    int* copy_levels = (int*)malloc(sizeof(int) * loop);

    while (i <= middle && j <= end) {
        if (levels[i] > levels[j]) {
            copy_levels[copy++] = levels[j++];
        }
        else {
            copy_levels[copy++] = levels[i++];
        }
    }

    while (i <= middle) {
        copy_levels[copy++] = levels[i++];
    }
    while (j <= end) {
        copy_levels[copy++] = levels[j++];
    }

    copy = 0;
    for (int k = start; k <= end; k++) {
        levels[k] = copy_levels[copy++];
    }
}