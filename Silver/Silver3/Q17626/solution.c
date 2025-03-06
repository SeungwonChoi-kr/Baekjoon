#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int target_num, index, max = 50000;
    scanf("%d", &target_num);

    int* countArr = (int*)calloc(max + 1, sizeof(int));

    int pivot = 1;
    int cur_root_num = 0;
    while (pivot <= target_num) {
        if (pivot == (cur_root_num + 1) * (cur_root_num + 1)) {
            countArr[pivot] = 1;
            cur_root_num++;
        } else {
            index = pivot - cur_root_num * cur_root_num;
            countArr[pivot] = countArr[index] + 1;

            if (pivot > 10) {
                for (int i = 1; i <= cur_root_num - 1; i++) {
                    index = pivot - (cur_root_num - i) * (cur_root_num - i);
                    int tmp = countArr[index] + 1;
                    if (tmp < countArr[pivot]) {
                        countArr[pivot] = tmp;
                    }
                }
            }
        }

        pivot++;
    }

    printf("%d", countArr[target_num]);

    return 0;
}