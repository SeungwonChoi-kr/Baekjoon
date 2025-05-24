#include <stdio.h>
#include <stdlib.h>

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

typedef struct Node {
    int day;
    int water;
} Node;

typedef struct Integer {
    int num;
    struct Integer* next;
} Integer;

typedef struct Queue {
    Integer *start, *end;
} Queue;

void insert_Queue(Queue* queue, int num);
Integer* pop_Queue(Queue* queue);
void watering(Node** dp, int N);

int main() {
    int N;
    scanf("%d", &N);

    Node** dp = (Node**)calloc(N + 1, sizeof(Node*));
    for (int i = 0; i <= N; i++) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->day = -1;
        node->water = -1;
        dp[i] = node;
    }

    if (N == 0) {
        printf("0 0");
    } else if (N >= 1) {
        dp[0]->day = 0;
        dp[0]->water = 0;
        dp[1]->day = 1;
        dp[1]->water = 1;

        if (N > 1) {
            watering(dp, N);
        }
        printf("%d %d", dp[N]->day, dp[N]->water);
    }

    return 0;
}

void insert_Queue(Queue* queue, int num) {
    Integer* integer = (Integer*)malloc(sizeof(Integer));
    integer->num = num;
    integer->next = NULL;

    if (queue->start == NULL) {
        queue->start = integer;
        queue->end = integer;
    } else {
        queue->end->next = integer;
        queue->end = integer;
    }
}

Integer* pop_Queue(Queue* queue) {
    if (queue->start == NULL)
        return NULL;

    Integer* integer = queue->start;
    queue->start = queue->start->next;
    if (queue->start == NULL) {
        queue->end = NULL;
    }
    return integer;
}

void watering(Node** dp, int N) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->start = NULL;
    queue->end = NULL;
    insert_Queue(queue, 1); // 1 size

    while (dp[N]->day == -1 || queue->start != NULL) {
        Integer* tmp = pop_Queue(queue);
        int size = tmp->num;
        free(tmp);
        if (size > N) {
            continue;
        }

        Node* node = dp[size];
        int day = node->day;
        int water = node->water;

        if (size + 1 <= N) {
            if (dp[size + 1]->day == -1) {
                dp[size + 1]->day = day + 1;
                dp[size + 1]->water = water + 1;
                insert_Queue(queue, size + 1);
            } else if (dp[size + 1]->day == day + 1) {
                dp[size + 1]->water = MIN(dp[size + 1]->water, water + 1);
            }
        }

        if (size * 3 <= N) {
            if (dp[size * 3]->day == -1) {
                dp[size * 3]->day = day + 1;
                dp[size * 3]->water = water + 3;
                insert_Queue(queue, size * 3);
            } else if (dp[size * 3]->day == day + 1) {
                dp[size * 3]->water = MIN(dp[size * 3]->water, water + 3);
            }
        }

        if (size <= 1000 && size * size <= N) {
            if (dp[size * size]->day == -1) {
                dp[size * size]->day = day + 1;
                dp[size * size]->water = water + 5;
                insert_Queue(queue, size * size);
            } else if (dp[size * size]->day == day + 1) {
                dp[size * size]->water = MIN(dp[size * size]->water, water + 5);
            }
        }
    }
}
