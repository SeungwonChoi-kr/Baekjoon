/* 미로 탐색 */
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

void init_Queue(Queue* q);
void insert_Queue(Queue* q, int row, int col);
Node* pop_Queue(Queue* q);
void bfs(bool** map, short** count, int dest_N, int dest_M);

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    bool** map = (bool**)malloc(N * sizeof(bool*));
    short** count = (short**)malloc(N * sizeof(short*));
    for (int i = 0; i < N; i++) {
        char* line = (char*)malloc((M + 1) * sizeof(char));
        scanf("%s", line);

        map[i] = (bool*)malloc(M * sizeof(bool));
        count[i] = (short*)calloc(M, sizeof(short));
        for (int j = 0; j < M; j++) {
            if (line[j] == '0') {
                map[i][j] = 0;
            } else if (line[j] == '1') {
                map[i][j] = 1;
            }
        }
    }

    bfs(map, count, N - 1, M - 1);

    printf("%d", count[N - 1][M - 1] + 1);

    return 0;
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

void bfs(bool** map, short** count, int dest_N, int dest_M) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    init_Queue(queue);
    insert_Queue(queue, 0, 0);

    map[0][0] = 0;

    Node* node = pop_Queue(queue);
    while (node) {
        int cur_row = node->row;
        int cur_col = node->col;

        // map[cur_row][cur_col] = 0;   // 태현짱 도와줘

        if (cur_row > 0 && map[cur_row - 1][cur_col] == 1) { // Up
            map[cur_row - 1][cur_col] = 0;
            count[cur_row - 1][cur_col] = count[cur_row][cur_col] + 1;
            insert_Queue(queue, cur_row - 1, cur_col);
        }
        if (cur_row < dest_N && map[cur_row + 1][cur_col] == 1) { // Down
            map[cur_row + 1][cur_col] = 0;
            count[cur_row + 1][cur_col] = count[cur_row][cur_col] + 1;
            insert_Queue(queue, cur_row + 1, cur_col);
        }
        if (cur_col > 0 && map[cur_row][cur_col - 1] == 1) { // Left
            map[cur_row][cur_col - 1] = 0;
            count[cur_row][cur_col - 1] = count[cur_row][cur_col] + 1;
            insert_Queue(queue, cur_row, cur_col - 1);
        }
        if (cur_col < dest_M && map[cur_row][cur_col + 1] == 1) { // Right
            map[cur_row][cur_col + 1] = 0;
            count[cur_row][cur_col + 1] = count[cur_row][cur_col] + 1;
            insert_Queue(queue, cur_row, cur_col + 1);
        }

        node = pop_Queue(queue);
    }
}