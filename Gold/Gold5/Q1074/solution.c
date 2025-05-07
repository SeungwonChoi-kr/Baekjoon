#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int search_crdnt(int N, int target_r, int target_c);

int main() {
    int N, target_r, target_c;
    scanf("%d %d %d", &N, &target_r, &target_c);

    int order = search_crdnt(N, target_r, target_c);
    printf("%d", order);

    return 0;
}

int search_crdnt(int N, int target_r, int target_c) {
    int row_low_bound = 0, row_high_bound = (int)pow(2.0, (double)N) - 1;
    int col_low_bound = 0, col_high_bound = (int)pow(2.0, (double)N) - 1;

    int order = 0, range, quadrant, row_pivot, col_pivot;
    bool Q_up, Q_left;

    while (N >= 1) {
        range = (int)pow(2.0, (double)N);
        range = range * range / 4;

        row_pivot = (row_low_bound + row_high_bound) / 2;
        col_pivot = (col_low_bound + col_high_bound) / 2;

        if (target_r <= row_pivot) {
            Q_up = true;
            row_high_bound = row_pivot;
        } else {
            Q_up = false;
            row_low_bound = row_pivot + 1;
        }
        if (target_c <= col_pivot) {
            Q_left = true;
            col_high_bound = col_pivot;
        } else {
            Q_left = false;
            col_low_bound = col_pivot + 1;
        }

        if (Q_up && Q_left) {
            quadrant = 0;
        } else if (Q_up && !Q_left) {
            quadrant = 1;
        } else if (!Q_up && Q_left) {
            quadrant = 2;
        } else if (!Q_up && !Q_left) {
            quadrant = 3;
        }

        order += range * quadrant;
        N--;
    }

    return order;
}
