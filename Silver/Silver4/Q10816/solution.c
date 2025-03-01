#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int upper = 0;
int lower = 0;

void merge(int* nums, int start, int middle, int end);
void mergeSort(int* nums, int start, int end);
void compare_lower(int* base_nums, int start, int end, int num, int N);
void compare_upper(int* base_nums, int start, int end, int num, int N);

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
        compare_lower(base_nums, 0, N - 1, search_nums[i], N);
        compare_upper(base_nums, 0, N - 1, search_nums[i], N);

        if (lower == -1 || upper == -1) {
            printf("0 ");
        }
        else {
            printf("%d ", upper - lower + 1);
        }
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

void compare_lower(int* base_nums, int start, int end, int num, int N) {
    int pivot = (start + end) / 2;

    if (start > end) {
        lower = -1;
        return;
    }

    if (base_nums[pivot] != num) {
        if (pivot + 1 < N) {
            if (base_nums[pivot + 1] == num) {
                lower = pivot + 1;
                return;
            }
            else if (base_nums[pivot] < num) {
                compare_lower(base_nums, pivot + 1, end, num, N);
            }
            else if (base_nums[pivot] > num) {
                compare_lower(base_nums, start, pivot - 1, num, N);
            }
        }
        else {
            lower = -1;
            return;
        }
    }
    else if (base_nums[pivot] == num) {
        if (pivot > 0) {
            if (base_nums[pivot - 1] != num) {
                lower = pivot;
                return;
            }
            else {
                compare_lower(base_nums, start, pivot - 1, num, N);
            }
        }
        else if (pivot == 0) {
            lower = pivot;
            return;
        }
    }
}

void compare_upper(int* base_nums, int start, int end, int num, int N) {
    int pivot = (start + end) / 2;

    if (start > end) {
        upper = -1;
        return;
    }

    if (base_nums[pivot] != num) {
        if (pivot != 0) {
            if (base_nums[pivot - 1] == num) {
                upper = pivot - 1;
                return;
            }
            else if (base_nums[pivot] < num) {
                compare_upper(base_nums, pivot + 1, end, num, N);
            }
            else if (base_nums[pivot] > num) {
                compare_upper(base_nums, start, pivot - 1, num, N);
            }
        }
        else if (pivot == 0)
        {
            if (base_nums[pivot + 1] == num) {
                upper = pivot + 1;
            }
            
        }
        
        else {
            upper = -1;
            return;
        }
    }
    else if (base_nums[pivot] == num) {
        if (pivot < N - 1) {
            if (base_nums[pivot + 1] != num) {
                upper = pivot;
                return;
            }
            else {
                compare_upper(base_nums, pivot + 1, end, num, N);
            }
        }
        else if (pivot == N - 1) {
            upper = pivot;
            return;
        }
    }
}