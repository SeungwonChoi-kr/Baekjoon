#include <stdio.h>
#include <stdlib.h>

typedef struct XY {
    int X;
    int Y;
} XY;

void merge(XY* xy, int start, int middle, int end);
void mergeSort(XY* xy, int start, int end);

int main() {
    int N;
    scanf("%d", &N);

    XY* xy = (XY*)malloc(sizeof(XY) * N);

    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        xy[i].X = x;
        xy[i].Y = y;
    }

    mergeSort(xy, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", xy[i].X, xy[i].Y);
    }

    return 0;
}

void merge(XY* xy, int start, int middle, int end) {
    int i = start;
    int j = middle + 1;
    int copy = 0;
    XY* copy_xy = (XY*)malloc(sizeof(XY) * (end - start + 1));

    while (i <= middle && j <= end) {
        if (xy[i].Y > xy[j].Y) {
            copy_xy[copy++] = xy[j++];
        }
        else if (xy[i].Y == xy[j].Y) {
            if (xy[i].X > xy[j].X) {
                copy_xy[copy++] = xy[j++];
            }
            else if (xy[i].X < xy[j].X) {
                copy_xy[copy++] = xy[i++];
            }
        }
        else if (xy[i].Y < xy[j].Y) {
            copy_xy[copy++] = xy[i++];
        }
    }

    while (i <= middle) {
        copy_xy[copy++] = xy[i++];
    }
    while (j <= end) {
        copy_xy[copy++] = xy[j++];
    }

    copy = 0;

    for (int k = start; k <= end; k++) {
        xy[k] = copy_xy[copy++];
    }
}

void mergeSort(XY* xy, int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;

        mergeSort(xy, start, middle);
        mergeSort(xy, middle + 1, end);

        merge(xy, start, middle, end);
    }
}