#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lower = 0;
int upper = 0;

void merge(int start, int middle, int end, int* nums);
void mergeSort(int start, int end, int* nums);
int mostNum(int* nums, int N);

int main() {
    int N;
    scanf("%d", &N);

    int* nums = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }
    mergeSort(0, N - 1, nums);

    // 산술 평균
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += nums[i];
    }
    sum = round(sum / N);
    if (sum <= 0 && sum > -1) {
        sum = 0;
    }
    printf("%.0lf\n", sum);

    // 중앙값
    printf("%d\n", nums[N / 2]);

    // 최빈값
    printf("%d\n", mostNum(nums, N));

    // 범위
    printf("%d", nums[N - 1] - nums[0]);

    return 0;
}

void merge(int start, int middle, int end, int* nums) {
    int i = start;
    int j = middle + 1;

    int* copy_nums = (int*)malloc((end - start + 1) * sizeof(int));
    int copy = 0;

    while (i <= middle && j <= end) {
        if (nums[i] <= nums[j]) {
            copy_nums[copy++] = nums[i++];
        }
        else {
            copy_nums[copy++] = nums[j++];
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

void mergeSort(int start, int end, int* nums) {
    if (start < end) {
        int middle = (start + end) / 2;

        mergeSort(start, middle, nums);
        mergeSort(middle + 1, end, nums);

        merge(start, middle, end, nums);
    }
}

int mostNum(int* nums, int N) {
    int most_freq = 0;
    int freq = 0;
    int num = 0;
    int dup = 1;

    if (N == 1) {
        return nums[0];
    }

    for (int i = 0; i < N - 1; i += freq) {
        freq = 1;

        for (int j = i + 1; j < N; j++) {
            if (nums[i] == nums[j]) {
                freq++;
            }
            else {
                break;
            }
        }
        if (freq > most_freq) {
            most_freq = freq;
            num = nums[i];
            dup = 1;
        }
        else if (freq == most_freq) {
            dup++;

            if (dup == 2) {
                num = nums[i];
            }
        }
    }

    return num;
}