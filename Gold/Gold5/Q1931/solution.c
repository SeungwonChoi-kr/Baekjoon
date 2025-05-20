#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Meeting {
    int start_time;
    int end_time;
    struct Meeting* next;
} Meeting;

typedef struct Queue {
    Meeting* start;
    Meeting* end;
} Queue;

void mergeSort(Meeting** time_plans, int s, int e);
void merge(Meeting** time_plans, int s, int m, int e);
void insert_Queue(Queue* q, Meeting* meeting);
int counting_meetings(Meeting** time_plans, int N);

int main() {
    int N, start_time, end_time;
    scanf("%d", &N);

    Meeting** time_plans = (Meeting**)malloc(N * sizeof(Meeting*));
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &start_time, &end_time);

        Meeting* meet = (Meeting*)malloc(sizeof(Meeting));
        meet->start_time = start_time;
        meet->end_time = end_time;
        meet->next = NULL;

        time_plans[i] = meet;
    }

    mergeSort(time_plans, 0, N - 1);
    int num = counting_meetings(time_plans, N);
    printf("%d", num);

    return 0;
}

void mergeSort(Meeting** time_plans, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;

        mergeSort(time_plans, s, m);
        mergeSort(time_plans, m + 1, e);

        merge(time_plans, s, m, e);
    }
}

void merge(Meeting** time_plans, int s, int m, int e) {
    int i = s, j = m + 1, idx = 0;
    Meeting** copy = (Meeting**)malloc((e - s + 1) * sizeof(Meeting*));

    while (i <= m && j <= e) {
        if (time_plans[i]->end_time < time_plans[j]->end_time) {
            copy[idx++] = time_plans[i++];
        } else if (time_plans[i]->end_time > time_plans[j]->end_time) {
            copy[idx++] = time_plans[j++];
        } else if (time_plans[i]->end_time == time_plans[j]->end_time) {
            if (time_plans[i]->start_time >= time_plans[j]->start_time) {
                copy[idx++] = time_plans[i++];
            } else {
                copy[idx++] = time_plans[j++];
            }
        }
    }
    while (i <= m) {
        copy[idx++] = time_plans[i++];
    }
    while (j <= e) {
        copy[idx++] = time_plans[j++];
    }

    idx = 0;
    for (int k = s; k <= e; k++) {
        time_plans[k] = copy[idx++];
    }
}

void insert_Queue(Queue* q, Meeting* meeting) {
    if (q->start == NULL) {
        q->start = meeting;
        q->end = meeting;
    } else {
        q->end->next = meeting;
        q->end = meeting;
    }
}

int counting_meetings(Meeting** time_plans, int N) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->start = NULL;
    q->end = NULL;
    int i = 0, cnt = 0;
    insert_Queue(q, time_plans[i++]);
    cnt++;

    while (i < N) {
        if (q->end->end_time == time_plans[i]->end_time) {
            if (q->end->start_time == q->end->end_time) {
                insert_Queue(q, time_plans[i++]);
                cnt++;
            } else {
                i++;
            }
        } else {
            if (q->end->end_time <= time_plans[i]->start_time) {
                insert_Queue(q, time_plans[i++]);
                cnt++;
            } else {
                i++;
            }
        }
    }

    return cnt;
}
