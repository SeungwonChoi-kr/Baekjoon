#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int priority;
    int order;
    struct Node* prev;
    struct Node* next;
} Node;

int ranking(int N, int M);

int main() {
    int T;
    scanf("%d", &T);

    int* results = (int*)malloc(sizeof(int) * T);

    for (int i = 0; i < T; i++) {
        int N, M;
        scanf("%d %d", &N, &M);

        results[i] = ranking(N, M);
    }

    for (int i = 0; i < T; i++) {
        printf("%d\n", results[i]);
    }

    return 0;
}

int ranking(int N, int M) {
    Node* papers = (Node*)malloc(sizeof(Node) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &papers[i].priority);
        papers[i].order = i;
    }

    for (int i = 0; i < N - 1; i++) {
        papers[i].next = &papers[i + 1];
        papers[N - 1 - i].prev = &papers[N - 2 - i];
    }
    papers[N - 1].next = &papers[0];
    papers[0].prev = &papers[N -1];


    bool isFound = false;
    int rank = 1;
    int remain_cnt = N;
    int dup_cnt = 0;
    int top_priority = 0;
    int target_priority = papers[M].priority;
    Node* pivot = &papers[0];
    Node* last_pivot = &papers[0];

    while (!isFound) {
        pivot = last_pivot;

        for (int i = 0; i < remain_cnt; i++) {  // 큐에서 가장 높은 우선 순위 파악
            if (pivot->priority > top_priority) {
                top_priority = pivot->priority;
            }
            pivot = pivot->next;
        }
        if (top_priority == target_priority) {
            for (int i = 0; i < remain_cnt; i++) {
                if (pivot->priority == top_priority) {
                    if (pivot->order == M) {
                        isFound = true;
                        break;
                    }
                    else {
                        rank++;
                    }
                }
                pivot = pivot->next;
            }
        }
        else {
            for (int i = 0; i < remain_cnt; i++) {
                if (pivot->priority == top_priority) {
                    pivot->prev->next = pivot->next;
                    pivot->next->prev = pivot->prev;
                    last_pivot = pivot->next;
                    rank++;
                    dup_cnt++;
                }
                pivot = pivot->next;
            }
            remain_cnt -= dup_cnt;
            dup_cnt = 0;
        }
        top_priority = 0;
    }

    return rank;
}