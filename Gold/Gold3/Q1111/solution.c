/* IQ Test */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPlus = false;
bool isMinus = false;
bool isPMCross = false;

void find_pattern(int N, int* nums);

int main() {
    // 초기 입력
    int N, *nums;
    scanf("%d", &N);
    nums = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);

        if (nums[i] >= 0) {
            isPlus = true;
        } else {
            isMinus = true;
        }

        if (isPlus && isMinus) {
            isPMCross = true;
        }
    }

    if (N > 2) {
        find_pattern(N, nums); // 문제가 원하는 상황
    } else {
        if (N == 2) { // 쉽게 구할 수 있는 상황
            if (nums[0] == nums[1]) {
                printf("%d", nums[0]);
            } else {
                printf("A");
            }
        } else {
            printf("A");
        }
    }

    return 0;
}

void find_pattern(int N, int* nums) {
    int a, b;
    if (isPMCross) {
        if (nums[0] < 0) {
        }
    } else if (isPlus) {
    } else {
    }
}
