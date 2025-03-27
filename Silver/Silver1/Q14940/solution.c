#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int row;
    int col;
    struct Node* link;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

void check(bool** map, int** count, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", count[i][j]);
        }
        printf("\n");
    }
    printf("\n");
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

void bfs(bool** map, int** count, int N, int M, int s_row, int s_col) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    init_Queue(queue);
    insert_Queue(queue, s_row, s_col);

    while (queue->head) {
        Node* node = pop_Queue(queue);
        int row = node->row;
        int col = node->col;

        if (row > 0) { // Up
            if (map[row - 1][col] == 1 && count[row - 1][col] == -1) {
                count[row - 1][col] = count[row][col] + 1;
                insert_Queue(queue, row - 1, col);
            }
        }
        if (row < N - 1) { // Down
            if (map[row + 1][col] == 1 && count[row + 1][col] == -1) {
                count[row + 1][col] = count[row][col] + 1;
                insert_Queue(queue, row + 1, col);
            }
        }
        if (col > 0) { // Left
            if (map[row][col - 1] == 1 && count[row][col - 1] == -1) {
                count[row][col - 1] = count[row][col] + 1;
                insert_Queue(queue, row, col - 1);
            }
        }
        if (col < M - 1) { // Right
            if (map[row][col + 1] == 1 && count[row][col + 1] == -1) {
                count[row][col + 1] = count[row][col] + 1;
                insert_Queue(queue, row, col + 1);
            }
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int s_row, s_col;

    bool** map = (bool**)malloc(N * sizeof(bool*));
    int** count = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        int zero_or_one;
        bool* map_row = (bool*)malloc(M * sizeof(bool));
        int* count_row = (int*)malloc(M * sizeof(int));
        for (int j = 0; j < M; j++) {
            scanf("%d", &zero_or_one);
            if (zero_or_one == 1) { // 길
                map_row[j] = 1;
            } else if (zero_or_one == 2) { // 시작점
                map_row[j] = 1;
                s_row = i;
                s_col = j;
            } else { // 벽
                map_row[j] = 0;
            }

            if (map_row[j] == 0) {
                count_row[j] = 0;
            } else {
                count_row[j] = -1;
            }
        }
        map[i] = map_row;
        count[i] = count_row;
    }
    count[s_row][s_col] = 0;    // 시작점까지의 거리를 0으로 초기화

    // check(map, count, N, M);
    bfs(map, count, N, M, s_row, s_col);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", count[i][j]);
        }
        printf("\n");
    }

    return 0;
}