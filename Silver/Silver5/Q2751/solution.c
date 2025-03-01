#include <stdlib.h>
#include <stdio.h>

void merge(int* nums, int start, int end, int middle);
void merge_sort(int* nums, int start, int end);

int main() {
    int N;
    scanf("%d", &N);

    int* nums = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }

    merge_sort(nums, 0, N - 1);
    
    for (int i = 0; i < N; i++) {
        printf("%d\n", nums[i]);
    }

    return 0;
}

void merge(int* nums, int start, int end, int middle) {
    int* tmp_nums = (int*)malloc(sizeof(int) * (end - start + 1));
    int i = start;
    int j = middle + 1;
    int copy_idx = 0;

    while (i <= middle && j <= end) {
        if (nums[i] < nums[j]) {
            tmp_nums[copy_idx++] = nums[i++];
        }
        else if (nums[i] > nums[j]) {
            tmp_nums[copy_idx++] = nums[j++];
        }
    }

    while (i <= middle) {
        tmp_nums[copy_idx++] = nums[i++];
    }
    while (j <= end) {
        tmp_nums[copy_idx++] = nums[j++];
    }
    
    copy_idx = 0;
    
    for (int i = start; i <= end; i++) {
        nums[i] = tmp_nums[copy_idx++];
    }
}

void merge_sort(int* nums, int start, int end) {
    if (start < end)
    {
        int middle = (start + end) / 2;

        merge_sort(nums, start, middle);
        merge_sort(nums, middle + 1, end);

        merge(nums, start, end, middle);
    }
}