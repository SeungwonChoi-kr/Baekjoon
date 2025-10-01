#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 131071

typedef struct Node {
    int num;
    int cnt;
    struct Node* next;
} Node;

Node* list[SIZE] = {NULL};

unsigned hashing(int num);
void insertHash(int num);
Node* searchHash(unsigned hashValue, int num);
void insertMaxHeap(int* maxHeap, int num, int size);
void insertMinHeap(int* minHeap, int num, int size);
void deleteMax(int* maxHeap, int size);
void deleteMin(int* minHeap, int size);

int main() {
    int T, k;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &k);
        getchar();

        char cmd;
        int num, size = 0;
        int* maxHeap = (int*)calloc(k + 1, sizeof(int));
        int* minHeap = (int*)calloc(k + 1, sizeof(int));
        for (int j = 0; j < k; j++) {
            scanf("%c", &cmd);
            scanf("%d", &num);
            getchar();

            if (cmd == 'I') {
                size++;
                insertHash(num);
                insertMaxHeap(maxHeap, num, size);
                insertMinHeap(minHeap, num, size);
            } else if (cmd == 'D') {
                if (size == 0)
                    continue;

                if (num == 1) {
                    deleteMax(maxHeap, size);
                } else if (num == -1) {
                    deleteMin(minHeap, size);
                }

                size--;
            }
        }

        if (size >= 2) {
            printf("%d %d\n", maxHeap[1], minHeap[1]);
        } else if (size == 1) {
            printf("%d %d\n", maxHeap[1], maxHeap[1]);
        } else {
            printf("EMPTY\n");
        }
        free(maxHeap);
        free(minHeap);
    }

    return 0;
}

unsigned hashing(int num) {
    unsigned hashValue = 0;

    if (num < 0)
        num *= -1;

    hashValue %= SIZE;

    return hashValue;
}

void insertHash(int num) {
    Node* node = (Node*)malloc(sizeof(Node));

    unsigned hashValue = hashing(num);
    Node* searching = searchHash(hashValue, num);

    if (searching != NULL) {
        searching->cnt++;
    } else {
        node->num = num;
        node->cnt = 1;
        node->next = list[hashValue];
        list[hashValue] = node;
    }
}

Node* searchHash(unsigned hashValue, int num) {
    Node* searching = list[hashValue];

    if (searching == NULL)
        return NULL;

    while (searching != NULL) {
        if (searching->num == num)
            if (searching->cnt > 0) {
                break;
            } else {
                return NULL;
            }
        else
            searching = searching->next;
    }

    return searching;
}

void insertMaxHeap(int* maxHeap, int num, int size) {
    int pos = size, tmp;
    maxHeap[pos] = num;

    while (pos != 1 && maxHeap[pos] > maxHeap[pos / 2]) {
        tmp = maxHeap[pos];
        maxHeap[pos] = maxHeap[pos / 2];
        maxHeap[pos / 2] = tmp;

        pos /= 2;
    }
}

void insertMinHeap(int* minHeap, int num, int size) {
    int pos = size, tmp;
    minHeap[pos] = num;

    while (pos != 1 && minHeap[pos] < minHeap[pos / 2]) {
        tmp = minHeap[pos];
        minHeap[pos] = minHeap[pos / 2];
        minHeap[pos / 2] = tmp;

        pos /= 2;
    }
}

void deleteMax(int* maxHeap, int size) {
    int pos = 1, tmp;
    maxHeap[1] = maxHeap[size--];

    while (1) {
        int left = pos * 2;
        int right = pos * 2 + 1;

        if (right <= size) {
            if (maxHeap[left] >= maxHeap[right]) {
                if (maxHeap[pos] < maxHeap[left]) {
                    tmp = maxHeap[pos];
                    maxHeap[pos] = maxHeap[left];
                    maxHeap[left] = tmp;

                    pos = left;
                } else {
                    break;
                }
            } else {
                if (maxHeap[pos] < maxHeap[right]) {
                    tmp = maxHeap[pos];
                    maxHeap[pos] = maxHeap[right];
                    maxHeap[right] = tmp;

                    pos = right;
                } else {
                    break;
                }
            }
        } else if (left <= size) {
            if (maxHeap[pos] < maxHeap[left]) {
                tmp = maxHeap[pos];
                maxHeap[pos] = maxHeap[left];
                maxHeap[left] = tmp;
            }
            break;
        } else {
            break;
        }
    }
}

void deleteMin(int* minHeap, int size) {
    int pos = 1, tmp;
    minHeap[1] = minHeap[size--];

    while (1) {
        int left = pos * 2;
        int right = pos * 2 + 1;

        if (right <= size) {
            if (minHeap[left] <= minHeap[right]) {
                if (minHeap[pos] > minHeap[left]) {
                    tmp = minHeap[pos];
                    minHeap[pos] = minHeap[left];
                    minHeap[left] = tmp;

                    pos = left;
                } else {
                    break;
                }
            } else {
                if (minHeap[pos] > minHeap[right]) {
                    tmp = minHeap[pos];
                    minHeap[pos] = minHeap[right];
                    minHeap[right] = tmp;

                    pos = right;
                } else {
                    break;
                }
            }
        } else if (left <= size) {
            if (minHeap[pos] > minHeap[left]) {
                tmp = minHeap[pos];
                minHeap[pos] = minHeap[left];
                minHeap[left] = tmp;
            }
            break;
        } else {
            break;
        }
    }
}