#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define POSSIBLE_MAX 350

typedef struct Node {
    int row;
    int col;
    struct Node* link;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

void bfs(bool** map, int* sizes, int N, int s_row, int s_col, int* size_cnt);
void init_Queue(Queue* q);
void insert_Queue(Queue* q, int row, int col);
Node* pop_Queue(Queue* q);
void mergeSort(int* arr, int s, int e);
void merge(int* arr, int s, int m, int e);

int main() {
    int N;
    int* sizes = (int*)calloc(POSSIBLE_MAX, sizeof(int));
    int size_cnt = 0;
    scanf("%d", &N);

    bool** map = (bool**)malloc(N * sizeof(bool*));
    for (int i = 0; i < N; i++) {
        char* line = (char*)malloc((N + 1) * sizeof(char));
        bool* map_row = (bool*)malloc(N * sizeof(bool));
        scanf("%s", line);

        for (int j = 0; j < N; j++) {
            if (line[j] == '0') {
                map_row[j] = 0;
            } else {
                map_row[j] = 1;
            }
        }
        map[i] = map_row;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1) {
                bfs(map, sizes, N, i, j, &size_cnt);
            }
        }
    }

    mergeSort(sizes, 0, size_cnt - 1);

    printf("%d\n", size_cnt);
    for (int i = 0; i < size_cnt; i++) {
        printf("%d\n", sizes[i]);
    }

    return 0;
}

void bfs(bool** map, int* sizes, int N, int s_row, int s_col, int* size_cnt) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    init_Queue(q);
    insert_Queue(q, s_row, s_col);
    int danji_size = 1;

    Node* node = pop_Queue(q);
    map[s_row][s_col] = 0;
    int row, col;
    while (node) {
        row = node->row;
        col = node->col;

        if (row > 0 && map[row - 1][col] == 1) { // Up
            map[row - 1][col] = 0;
            insert_Queue(q, row - 1, col);
            danji_size++;
        }
        if (row < N - 1 && map[row + 1][col] == 1) { // Down
            map[row + 1][col] = 0;
            insert_Queue(q, row + 1, col);
            danji_size++;
        }
        if (col > 0 && map[row][col - 1] == 1) { // Left
            map[row][col - 1] = 0;
            insert_Queue(q, row, col - 1);
            danji_size++;
        }
        if (col < N - 1 && map[row][col + 1] == 1) { // Right
            map[row][col + 1] = 0;
            insert_Queue(q, row, col + 1);
            danji_size++;
        }

        node = pop_Queue(q);
    }

    sizes[*size_cnt] = danji_size;
    *size_cnt += 1;
}

void init_Queue(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

void insert_Queue(Queue* q, int row, int col) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->link = NULL;

    if (q->head == NULL) {
        q->head = node;
        q->tail = node;
    } else {
        q->tail->link = node;
        q->tail = node;
    }
}

Node* pop_Queue(Queue* q) {
    if (q->head == NULL) {
        return NULL;
    }

    Node* node = q->head;
    q->head = q->head->link;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    return node;
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
    int* copy = (int*)malloc((e - s + 1) * sizeof(int));
    int i = s, j = m + 1;
    int idx = 0;

    while (i <= m && j <= e) {
        if (arr[i] < arr[j]) {
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
    free(copy);
}