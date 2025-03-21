#include <stdio.h>
#include <stdlib.h>
#define MAX 51

char lane[MAX][MAX] = {'\0'};

void mergeSort(int* arr, int s, int e);
void merge(int* arr, int s, int m, int e);
int* eraseDup(int* arr, int s, int e);

int main() {
    int R, C, dot_cnt;
    int teams[10];
    int* scores = (int*)malloc(10 * sizeof(int));
    scanf("%d %d", &R, &C);

    for (int i = 0; i < 10; i++) {
        teams[i] = -1;
    }

    for (int i = 0; i < R; i++) {
        dot_cnt = 0;
        for (int j = 0; j < C; j++) {
            scanf(" %c", &lane[i][j]);
            if (lane[i][j] >= '1' && lane[i][j] <= '9') {
                if (teams[(lane[i][j] - '0')] == -1) {
                    teams[(lane[i][j] - '0')] = dot_cnt;
                    scores[(lane[i][j] - '0')] = dot_cnt;
                }
            }

            if (lane[i][j] == '.') {
                dot_cnt++;
            }
        }
    }

    mergeSort(scores, 1, 9);
    int* grades = eraseDup(scores, 1, 9);
    // for (int i = 1; i <= 9; i++) {
    //     printf("%d\n", scores[i]);
    // }

    // printf("-----\n");
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (teams[i] == grades[j]) {
                printf("%d\n", j);
                break;
            }
        }
    }

    return 0;
}

void mergeSort(int* arr, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(arr, s, m);
        mergeSort(arr, m + 1, e);
        merge(arr, s, m, e);
    }
}

void merge(int* arr, int s, int m, int e) {
    int i = s, j = m + 1, idx = 0;
    int* copy = (int*)malloc((e - s + 1) * sizeof(int));

    while (i <= m && j <= e) {
        if (arr[i] > arr[j]) {
            copy[idx++] = arr[i++];
        } else {
            copy[idx++] = arr[j++];
        }
    }

    while (i <= m) {
        copy[idx++] = arr[i++];
    }
    while (j <= e) {
        copy[idx++] = arr[j++];
    }

    idx = 0;
    for (int k = s; k <= e; k++) {
        arr[k] = copy[idx++];
    }
}

int* eraseDup(int* arr, int s, int e) {
    int* grades = (int*)malloc(10 * sizeof(int));
    for (int i = 1; i <= 9; i++) {
        grades[i] = -1;
    }

    int last_score = arr[1], idx = 1;
    grades[idx++] = arr[1];

    for (int i = 2; i <= 9; i++) {
        if (arr[i] == last_score) {
            continue;
        } else {
            grades[idx++] = arr[i];
            last_score = arr[i];
        }
    }
    return grades;
}
