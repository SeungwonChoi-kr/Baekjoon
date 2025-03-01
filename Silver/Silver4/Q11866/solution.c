#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    struct Node* next;
} Node;


int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    Node* point = NULL;

    Node* node = (Node*)malloc(sizeof(Node));
    Node* start = node;
    node->num = 1;
    node->next = NULL;
    point = node;

    for (int i = 2; i <= N; i++) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->num = i;

        point->next = node;
        point = node;
    }
    point->next = start;

    point = start;
    Node* pre;

    printf("<");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K - 1; j++) {
            pre = point;
            point = point->next;
        }
        printf("%d", point->num);

        if (i < N - 1) {
            printf(", ");
        }

        pre->next = point->next;
        point = point->next;
    }
    printf(">");

    return 0;
}