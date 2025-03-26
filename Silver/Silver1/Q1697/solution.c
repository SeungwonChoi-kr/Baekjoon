/* 숨바꼭질 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

typedef struct Node {
    int num;
    struct Node* link;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

void init_Queue(Queue* q);
void insert_Queue(Queue* q, int num);
Node* pop_Queue(Queue* q);
void print_Queue(Queue* q);
void bfs(int A, int B, bool* visited, int* cnt_arr, Queue* queue);

int main() {
    // 변수 입력
    int A, B;
    scanf("%d %d", &A, &B);

    // 계산에 필요한 변수 선언
    bool* visited = (bool*)calloc(MAX, sizeof(bool));
    int* cnt_arr = (int*)calloc(MAX, sizeof(int));
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    init_Queue(queue);

    // 계산 및 출력
    visited[A] = true;
    cnt_arr[A] = 0;
    bfs(A, B, visited, cnt_arr, queue);
    printf("%d", cnt_arr[B]);

    return 0;
}

void init_Queue(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

void insert_Queue(Queue* q, int num) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->num = num;
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

void print_Queue(Queue* q) {
    Node* node = q->head;
    while (node) {
        printf("%d ", node->num);
        node = node->link;
    }
    printf("\n");
}

void bfs(int A, int B, bool* visited, int* cnt_arr, Queue* queue) {
    insert_Queue(queue, A);
    visited[A] = true;
    cnt_arr[A] = 0;

    while (queue->head) {
        Node* node = pop_Queue(queue);
        int pivot = node->num;
        free(node);

        if (pivot == B) {
            return;
        }

        if (pivot - 1 >= 0 && !visited[pivot - 1]) {
            visited[pivot - 1] = true;
            cnt_arr[pivot - 1] = cnt_arr[pivot] + 1;
            insert_Queue(queue, pivot - 1);
        }
        if (pivot < B) {
            if (!visited[pivot + 1]) {
                visited[pivot + 1] = true;
                cnt_arr[pivot + 1] = cnt_arr[pivot] + 1;
                insert_Queue(queue, pivot + 1);
            }
            if (pivot * 2 < MAX && !visited[pivot * 2]) {
                visited[pivot * 2] = true;
                cnt_arr[pivot * 2] = cnt_arr[pivot] + 1;
                insert_Queue(queue, pivot * 2);
            }
        }
    }
}