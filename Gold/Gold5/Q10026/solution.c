#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int r;
    int c;
    char color;
    struct Node* next;
} Node;

typedef struct QUEUE {
    Node* head;
    Node* tail;
} QUEUE;

void insert_queue(QUEUE* queue, int r, int c, char color, char** map);
bool is_empty(QUEUE* queue);
Node* pop_queue(QUEUE* queue);
void init_queue(QUEUE* queue);
void init_map(char** map, int N);
void bfs(QUEUE* diff_queue, char** map, int N, int r, int c, char color);

int main() {
    int N, RGB_count = 0, GB_count = 0;
    scanf("%d", &N);

    char** map = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        char* line = (char*)malloc((N + 1) * sizeof(char));
        scanf("%s", line);
        map[i] = line;
    }

    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    init_queue(queue);
    int s_row = 0, s_col = 0;
    char s_color = map[s_row][s_col];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'R' || map[i][j] == 'G' || map[i][j] == 'B') {
                bfs(queue, map, N, i, j, map[i][j]);
                RGB_count++;
            }
        }
    }

    init_map(map, N);
    init_queue(queue);
    s_row = 0;
    s_col = 0;
    s_color = map[s_row][s_col];
    insert_queue(queue, s_row, s_col, s_color, map);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'R' || map[i][j] == 'G' || map[i][j] == 'B') {
                bfs(queue, map, N, i, j, map[i][j]);
                GB_count++;
            }
        }
    }

    printf("%d %d", RGB_count, GB_count);

    return 0;
}

void insert_queue(QUEUE* queue, int r, int c, char color, char** map) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->r = r;
    node->c = c;
    node->color = color;
    node->next = NULL;

    if (queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }

    if (map[r][c] == 'R') {
        map[r][c] = 'r';
    } else if (map[r][c] == 'G') {
        map[r][c] = 'g';
    } else if (map[r][c] == 'B') {
        map[r][c] = 'b';
    }
}

bool is_empty(QUEUE* queue) {
    if (queue->head == NULL)
        return true;
    else
        return false;
}

Node* pop_queue(QUEUE* queue) {
    if (queue->head == NULL)
        return NULL;

    Node* node = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    return node;
}

void init_queue(QUEUE* queue) {
    Node* node = queue->head;

    while (node != NULL) {
        Node* tmp = node;
        node = node->next;
        free(tmp);
    }

    queue->head = NULL;
    queue->tail = NULL;
}

void init_map(char** map, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'r' || map[i][j] == 'g') {
                map[i][j] = 'R';
            } else if (map[i][j] == 'b') {
                map[i][j] = 'B';
            }
        }
    }
}

void bfs(QUEUE* queue, char** map, int N, int r, int c, char color) {
    Node* node;
    insert_queue(queue, r, c, map[r][c], map);

    while (1) {
        node = pop_queue(queue);
        if (node == NULL) {
            break;
        }
        r = node->r;
        c = node->c;
        color = node->color;

        if (r > 0 && color == map[r - 1][c]) { // Up
            insert_queue(queue, r - 1, c, color, map);
        }
        if (r < N - 1 && color == map[r + 1][c]) { // Down
            insert_queue(queue, r + 1, c, color, map);
        }
        if (c > 0 && color == map[r][c - 1]) { // Left
            insert_queue(queue, r, c - 1, color, map);
        }
        if (c < N - 1 && color == map[r][c + 1]) { // Right
            insert_queue(queue, r, c + 1, color, map);
        }

        free(node);
    }
}