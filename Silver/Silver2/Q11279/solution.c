#include <stdio.h>
#include <stdlib.h>
#define MAX 200010

void insertHeap(unsigned* heap, unsigned num, unsigned* size);
void popHeap(unsigned* heap, unsigned* size);

int main() {
    unsigned N, num;
    scanf("%d", &N);

    unsigned heap[MAX], size = 0;
    for (unsigned i = 0; i < N; i++) {
        scanf("%d", &num);
        if (num == 0) {
            popHeap(heap, &size);
        } else {
            insertHeap(heap, num, &size);
        }
    }

    return 0;
}

void insertHeap(unsigned* heap, unsigned num, unsigned* size) {
    unsigned i = 1, tmp = 0;
    i += *size;
    heap[i] = num;

    while (i != 1) {
        if (heap[i] > heap[i / 2]) {
            tmp = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = tmp;
            i /= 2;
        } else {
            break;
        }
    }
    *size += 1;
}

void popHeap(unsigned* heap, unsigned* size) {
    if (heap[1] == 0) { // 비어있을 경우
        printf("0\n");
        return;
    }

    unsigned i = *size;
    if (i == 1) {
        printf("%d\n", heap[1]);
        heap[1] = 0;
        (*size)--;
        return;
    } else {
        printf("%d\n", heap[1]);
        heap[1] = heap[i];
        heap[i] = 0;
        (*size)--;
    }

    unsigned tmp = 0;
    i = 1;
    while (1) {
        if (heap[i * 2] > heap[i * 2 + 1]) {
            if (heap[i * 2] > heap[i]) {
                tmp = heap[i];
                heap[i] = heap[i * 2];
                heap[i * 2] = tmp;
            } else {
                break;
            }
            i = i * 2;
        } else {
            if (heap[i * 2 + 1] == 0) {
                break;
            }

            if (heap[i * 2 + 1] > heap[i]) {
                tmp = heap[i];
                heap[i] = heap[i * 2 + 1];
                heap[i * 2 + 1] = tmp;
            } else {
                break;
            }
            i = i * 2 + 1;
        }
    }
}
