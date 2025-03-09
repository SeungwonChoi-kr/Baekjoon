#include <stdio.h>

void insertHeap(int* heap, int num, int* heap_size);
void swapHeap(int* heap, int idx);
void removeHeap(int* heap, int* heap_size);

int main() {
    int N;
    scanf("%d", &N);

    int heap[200010] = {
        0,
    };

    int num;
    int heap_size = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);

        if (num == 0) {
            removeHeap(heap, &heap_size);
        } else {
            insertHeap(heap, num, &heap_size);
        }
    }

    return 0;
}

void insertHeap(int* heap, int num, int* heap_size) {
    heap[*heap_size + 1] = num;

    swapHeap(heap, *heap_size + 1);
    (*heap_size)++;
}

void swapHeap(int* heap, int idx) {
    int tmp;
    while (idx > 1 && heap[idx] < heap[idx / 2]) {
        tmp = heap[idx];
        heap[idx] = heap[idx / 2];
        heap[idx / 2] = tmp;

        idx /= 2;
    }
}

void removeHeap(int* heap, int* heap_size) {
    printf("%d\n", heap[1]);
    if (heap[1] == 0) {
        return;
    }

    heap[1] = heap[*heap_size];
    heap[*heap_size] = 0;
    (*heap_size)--;

    int tmp;
    int i = 1;
    while (heap[i] > heap[2 * i] || heap[i] > heap[2 * i + 1]) {
        if (heap[2 * i] == 0) {
            break;
        } else if (heap[2 * i + 1] == 0) {
            if (heap[i] > heap[2 * i]) {
                tmp = heap[i];
                heap[i] = heap[2 * i];
                heap[2 * i] = tmp;
            }
            break;
        }

        if (heap[2 * i] < heap[2 * i + 1]) {
            tmp = heap[2 * i];
            heap[2 * i] = heap[i];
            heap[i] = tmp;

            i = 2 * i;
        } else {
            tmp = heap[2 * i + 1];
            heap[2 * i + 1] = heap[i];
            heap[i] = tmp;

            i = 2 * i + 1;
        }
    }
}