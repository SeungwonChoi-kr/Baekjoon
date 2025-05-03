#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    int distance;
    struct Node* link;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

void init_Queue(Queue* queue);
void insert_Queue(Queue* queue, int num, int distance);
Node* pop_Queue(Queue* queue);
void search_min_road(int** map, int* distance_to_one, int n);

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** map = (int**)calloc(n + 1, sizeof(int*));
    for (int i = 1; i <= n; i++) {
        int* map_row = (int*)calloc(n + 1, sizeof(int));
        map[i] = map_row;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        map[a][b] = 1;
        map[b][a] = 1;
    }

    int loop;
    scanf("%d", &loop);

    int* distance_to_one = (int*)calloc(n + 1, sizeof(int));
    int a, b;

    for (int i = 0; i < loop; i++) {
        scanf("%d %d", &a, &b);

        map[a][b] = 1;
        map[b][a] = 1;

        distance_to_one[1] = 0;
        for (int i = 2; i <= n; i++) {
            distance_to_one[i] = -1;
        }
        search_min_road(map, distance_to_one, n);

        for (int i = 1; i <= n; i++) {
            printf("%d ", distance_to_one[i]);
        }
        printf("\n");
    }

    return 0;
}

void init_Queue(Queue* queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

void insert_Queue(Queue* queue, int num, int distance) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->num = num;
    node->distance = distance;
    node->link = NULL;

    if (queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->link = node;
        queue->tail = node;
    }
}

Node* pop_Queue(Queue* queue) {
    if (queue->head == NULL)
        return NULL;

    Node* node = queue->head;
    queue->head = queue->head->link;

    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    return node;
}

void search_min_road(int** map, int* distance_to_one, int n) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    init_Queue(queue);

    int* visited = (int*)calloc(n + 1, sizeof(int));
    visited[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (map[1][i] == 1) {
            insert_Queue(queue, i, 1);
            visited[i] = 1;
            distance_to_one[i] = 1;
        }
    }

    Node* node = pop_Queue(queue);
    while (node) {
        for (int i = 1; i <= n; i++) {
            if (map[node->num][i] == 1 && visited[i] == 0) {
                insert_Queue(queue, i, node->distance + 1);
                visited[i] = 1;
                distance_to_one[i] = node->distance + 1;
            }
        }

        node = pop_Queue(queue);
    }
}