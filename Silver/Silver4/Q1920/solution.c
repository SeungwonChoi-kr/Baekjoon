#include <stdio.h>
#include <stdlib.h>

void merge(int* nums, int start, int middle, int end);
void mergeSort(int* nums, int start, int end);
void compare(int* base_nums, int start, int end, int num);

int main() {
    int N;
    scanf("%d", &N);

    int* base_nums = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &base_nums[i]);
    }
    mergeSort(base_nums, 0, N - 1);

    int M;
    scanf("%d", &M);

    int* search_nums = (int*)malloc(sizeof(int) * M);

    for (int i = 0; i < M; i++) {
        scanf("%d", &search_nums[i]);
    }

    for (int i = 0; i < M; i++) {
        compare(base_nums, 0, N - 1, search_nums[i]);
    }

    return 0;
}

void merge(int* nums, int start, int middle, int end) {
    int i = start;
    int j = middle + 1;
    int copy = 0;
    int* copy_nums = (int*)malloc(sizeof(int) * (end - start + 1));

    while (i <= middle && j <= end) {
        if (nums[i] > nums[j]) {
            copy_nums[copy++] = nums[j++];
        }
        else {
            copy_nums[copy++] = nums[i++];
        }
    }

    while (i <= middle) {
        copy_nums[copy++] = nums[i++];
    }
    while (j <= end) {
        copy_nums[copy++] = nums[j++];
    }

    copy = 0;
    for (int k = start; k <= end; k++) {
        nums[k] = copy_nums[copy++];
    }
}

void mergeSort(int* nums, int start, int end) {
    if (start < end)
    {
        int middle = (start + end) / 2;

        mergeSort(nums, start, middle);
        mergeSort(nums, middle + 1, end);

        merge(nums, start, middle, end);
    }
}

void compare(int* base_nums, int start, int end, int num) {
    if (start <= end) {
        int pivot = (start + end) / 2;

        if (base_nums[pivot] > num) {
            compare(base_nums, start, pivot - 1, num);
        }
        else if (base_nums[pivot] < num) {
            compare(base_nums, pivot + 1, end, num);
        }
        else {
            printf("1\n");
        }
    }
    else {
        printf("0\n");
    }
}