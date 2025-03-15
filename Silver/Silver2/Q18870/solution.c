#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int* arr, int s, int e);
void merge(int* arr, int s, int m, int e);
int find_upper(int* arr, int N, int num);
int find_lower(int* arr, int N, int num);
int* eraseDup(int* arr, int N, int* size);

int main() {
    int N;
    scanf("%d", &N);

    int* origin = (int*)malloc(N * sizeof(int));
    int* arr = (int*)malloc(N * sizeof(int));
    int* perfect_arr;
    int size = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        origin[i] = arr[i];
    }
    mergeSort(arr, 0, N - 1);
    perfect_arr = eraseDup(arr, N, &size);

    // for (int i = 0; i < N; i++) {
    //     printf("%d ", origin[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < N; i++) {
    //     printf("%d ", arr[i]);
    // }

    // printf("\n");
    // for (int i = 0; i < size; i++) {
    //     printf("%d ", perfect_arr[i]);
    // }
    // printf("\n");
    free(arr);
    for (int i = 0; i < N; i++) {
        printf("%d ", find_lower(perfect_arr, size, origin[i]));
    }

    return 0;
}

void mergeSort(int* arr, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;

        mergeSort(arr, s, m);
        mergeSort(arr, m + 1, e);

        merge(arr, s, m, e);
    }
}

void merge(int* arr, int s, int m, int e) {
    int* copy = (int*)malloc((e - s + 1) * sizeof(int));
    int i = s, j = m + 1, idx = 0;

    while (i <= m && j <= e) {
        if (arr[i] < arr[j]) {
            copy[idx++] = arr[i++];
        } else {
            copy[idx++] = arr[j++];
        }
    }

    while (i <= m) {
        copy[idx++] = arr[i++];
    }
    while (j <= e) {
        copy[idx++] = arr[j++];
    }

    idx = 0;
    for (int k = s; k <= e; k++) {
        arr[k] = copy[idx++];
    }
}

int find_upper(int* arr, int N, int num) {
    int left = 0, right = N;
    int pivot;

    while (left < right) {
        pivot = (left + right) / 2;

        if (arr[pivot] <= num) {
            left = pivot + 1;
        } else {
            right = pivot;
        }
    }

    return left;
}

int find_lower(int* arr, int N, int num) {
    int left = 0, right = N, pivot;

    while (left < right) {
        pivot = (left + right) / 2;

        if (arr[pivot] < num) {
            left = pivot + 1;
        } else {
            right = pivot;
        }
    }

    return right;
}

int* eraseDup(int* arr, int N, int* size) {
    int* copy = (int*)malloc(N * sizeof(int));
    int* perfect_size_arr;
    int cnt = 0, idx = 0;

    while (idx < N) {
        copy[cnt++] = arr[idx];
        idx = find_upper(arr, N, arr[idx]);
    }

    perfect_size_arr = (int*)malloc((cnt) * sizeof(int));
    for (int i = 0; i < cnt; i++) {
        perfect_size_arr[i] = copy[i];
    }
    free(copy);

    *size = cnt;
    return perfect_size_arr;
}