#include <stdio.h>
#include <stdlib.h>

void merge(int start, int middle, int end, int* minutes);
void mergeSort(int start, int end, int* minutes);
int atm(int N, int* minutes);

int main() {
    int N;
    scanf("%d", &N);

    int* minutes = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &minutes[i]);
    }

    mergeSort(0, N - 1, minutes);
    printf("%d", atm(N, minutes));

    return 0;
}

void merge(int start, int middle, int end, int* minutes) {
    int i = start;
    int j = middle + 1;
    int n = 0;
    int* copy = (int*)malloc((end - start + 1) * sizeof(int));

    while (i <= middle && j <= end) {
        if (minutes[i] <= minutes[j])
            copy[n++] = minutes[i++];
        else
            copy[n++] = minutes[j++];
    }
    while (i <= middle) {
        copy[n++] = minutes[i++];
    }
    while (j <= end) {
        copy[n++] = minutes[j++];
    }

    n = 0;
    for (int k = start; k <= end; k++) {
        minutes[k] = copy[n++];
    }
}

void mergeSort(int start, int end, int* minutes) {
    if (start < end) {
        int middle = (start + end) / 2;

        mergeSort(start, middle, minutes);
        mergeSort(middle + 1, end, minutes);

        merge(start, middle, end, minutes);
    }
}

int atm(int N, int* minutes) {
    int all = 0;

    for (int i = 1; i < N; i++) {
        minutes[i] += minutes[i - 1];
    }

    for (int i = 0; i < N; i++) {
        all += minutes[i];
    }

    return all;
}