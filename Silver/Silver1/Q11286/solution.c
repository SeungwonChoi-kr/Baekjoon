#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BOTH_EMPTY 0
#define POS_EMPTY 1
#define NEG_EMPTY -1
#define NON_EMPTY 2

int isEmpty(long long* posArr, long long* negArr);
long long popHeap(long long* arr);
void reformHeap(long long* arr);
void insertHeap(long long* arr, long long num);

int main() {
    int command_num;
    long long command;
    scanf("%d", &command_num);

    long long* posArr = (long long*)calloc(100001, sizeof(long long));
    long long* negArr = (long long*)calloc(100001, sizeof(long long));
    posArr[0] = 0; // size
    negArr[0] = 0; // size

    int status;
    long long num;
    for (int i = 0; i < command_num; i++) {
        scanf("%lld", &command);
        if (command == 0) {
            status = isEmpty(posArr, negArr);
            if (status == BOTH_EMPTY) {
                printf("0\n");
            } else if (status == POS_EMPTY) {
                num = popHeap(negArr);
                printf("-%lld\n", num);
            } else if (status == NEG_EMPTY) {
                num = popHeap(posArr);
                printf("%lld\n", num);
            } else {
                if (negArr[1] <= posArr[1]) {
                    num = popHeap(negArr);
                    printf("-%lld\n", num);
                } else {
                    num = popHeap(posArr);
                    printf("%lld\n", num);
                }
            }
        } else if (command > 0) {
            insertHeap(posArr, command);
        } else if (command < 0) {
            insertHeap(negArr, -1 * command);
        }
    }

    return 0;
}

int isEmpty(long long* posArr, long long* negArr) {
    if (posArr[0] == 0 && negArr[0] == 0) {
        return BOTH_EMPTY;
    } else if (posArr[0] == 0) {
        return POS_EMPTY;
    } else if (negArr[0] == 0) {
        return NEG_EMPTY;
    } else {
        return NON_EMPTY;
    }
}

long long popHeap(long long* arr) {
    long long num = arr[1];

    arr[1] = arr[arr[0]];
    arr[0]--;

    reformHeap(arr);

    return num;
}

void reformHeap(long long* arr) {
    int pivot = 1;

    long long *parent, *left, *right;
    long long tmp;
    while (true) {
        if (pivot * 2 + 1 <= arr[0]) {
            parent = &arr[pivot];
            left = &arr[pivot * 2];
            right = &arr[pivot * 2 + 1];

            if (*left <= *right) {
                if (*parent <= *left)
                    break;

                tmp = *parent;
                *parent = *left;
                *left = tmp;

                pivot = pivot * 2;
            } else {
                if (*parent <= *right)
                    break;

                tmp = *parent;
                *parent = *right;
                *right = tmp;

                pivot = pivot * 2 + 1;
            }
        } else if (pivot * 2 <= arr[0]) {
            parent = &arr[pivot];
            left = &arr[pivot * 2];

            if (*parent <= *left)
                break;

            tmp = *parent;
            *parent = *left;
            *left = tmp;

            pivot = pivot * 2;
        } else {
            break;
        }
    }
}

void insertHeap(long long* arr, long long num) {
    arr[0]++;
    arr[arr[0]] = num;

    int pivot = arr[0];
    long long *child, *parent;
    long long tmp;
    while (true) {
        if (pivot == 1)
            break;

        child = &arr[pivot];
        parent = &arr[pivot / 2];
        if (*child < *parent) {
            tmp = *parent;
            *parent = *child;
            *child = tmp;

            pivot /= 2;
        } else {
            break;
        }
    }
}