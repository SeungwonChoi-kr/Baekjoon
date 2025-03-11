#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int* arr, int start, int end);
void merge(int* arr, int start, int middle, int end);
int cutting_tree(int* trees, int tree_num, int cutter_length, int need_length);

int main() {
    int tree_num, need_length, cutting_length;
    scanf("%d %d", &tree_num, &need_length);

    int* trees = (int*)malloc(tree_num * sizeof(int));
    for (int i = 0; i < tree_num; i++) {
        scanf("%d", &trees[i]);
    }

    mergeSort(trees, 0, tree_num - 1);
    cutting_length = cutting_tree(trees, tree_num, (trees[0] + trees[tree_num - 1]) / 2, need_length);
    printf("%d", cutting_length);

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
}

int cutting_tree(int* trees, int tree_num, int cutter_length, int need_length) {
    int cut_length = 0;
    bool overCut = false;

    for (int i = 0; i < tree_num; i++) {
        cut_length += trees[i] - cutter_length;

        if (cut_length > need_length) {
            overCut = true;

            if (i + 1 == tree_num) {
                overCut = false;
            }
        }
    }

    if (cut_length > need_length) {
        cutting_tree(trees, tree_num, cutter_length / 2, need_length);
    }

    return 0;
}
