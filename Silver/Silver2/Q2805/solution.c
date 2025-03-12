#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int* arr, int start, int end);
void merge(int* arr, int start, int middle, int end);
long check_remainder(int* trees, long need_length, long s, long e, long tree_num);
int cutting_tree(int* trees, long saw_length, long need_length, long tree_num);

int main() {
    long tree_num, need_length;
    long saw_length;
    scanf("%ld %ld", &tree_num, &need_length);

    int* trees = (int*)malloc(tree_num * sizeof(int));
    for (int i = 0; i < tree_num; i++) {
        scanf("%d", &trees[i]);
    }
    mergeSort(trees, 0, tree_num - 1);

    saw_length = check_remainder(trees, need_length, 0, trees[0], tree_num);
    printf("%ld", saw_length);

    return 0;
}

void mergeSort(int* arr, int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;

        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);

        merge(arr, start, middle, end);
    }
}

void merge(int* arr, int start, int middle, int end) {
    int* copy = (int*)malloc((end - start + 1) * sizeof(int));
    int i = start, j = middle + 1;
    int idx = 0;

    while (i <= middle && j <= end) {
        if (arr[i] > arr[j]) {
            copy[idx++] = arr[i++];
        } else {
            copy[idx++] = arr[j++];
        }
    }

    while (i <= middle) {
        copy[idx++] = arr[i++];
    }
    while (j <= end) {
        copy[idx++] = arr[j++];
    }

    idx = 0;
    for (int k = start; k <= end; k++) {
        arr[k] = copy[idx++];
    }
    free(copy);
}

long check_remainder(int* trees, long need_length, long s, long e, long tree_num) {
    long p = 0, result = 0;

    while (s + 1 < e) {
        p = (s + e) / 2;
        result = cutting_tree(trees, p, need_length, tree_num);

        // printf("(%ld, %ld) r[%ld]: %ld\n", s, e, p, result);

        if (result > 0) {
            s = p;
        } else if (result == 0) {
            s = p;
        } else {
            e = p - 1;
        }
    }

    if (result < 0) {
        p--;

        if (cutting_tree(trees, p, need_length, tree_num) < 0) {
            p--;
        }
    } else if (result > 0) {
        if (cutting_tree(trees, p + 1, need_length, tree_num) >= 0) {
            p++;
        }
    }

    return p;
}

int cutting_tree(int* trees, long saw_length, long need_length, long tree_num) {
    long remainder = 0;
    for (int i = 0; i < tree_num; i++) {
        if (trees[i] - saw_length > 0) {
            remainder += trees[i] - saw_length;
        } else {
            break;
        }
    }
    remainder -= need_length;

    if (remainder > 0) {
        remainder = 1;
    } else if (remainder < 0) {
        remainder = -1;
    }

    return remainder;
}