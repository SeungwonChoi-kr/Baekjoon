#include <stdio.h>
#include <stdlib.h>

typedef struct Coor {
    int row;
    int col;
    int height;
    int day;
    struct Coor* next;
} Coor;

typedef struct Queue {
    Coor *start, *end;
} Queue;

void insert_Queue(Queue* queue, int row, int col, int height, int day);
Coor* pop_Queue(Queue* queue);
void bfs(short** box, Queue* queue, int R, int C, int H, int* colored_tomato, int* longest_day);
void show_box(short** box, int R, int C, int H);

int main() {
    int R, C, H, cur_tomato = 0, colored_tomato = 0, longest_day = 0;
    scanf("%d %d %d", &C, &R, &H);

    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->start = NULL;
    queue->end = NULL;

    short** box = (short**)calloc(R * H, sizeof(short*));
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < R; i++) {
            short* line = (short*)calloc(C, sizeof(short));
            for (int j = 0; j < C; j++) {
                scanf("%hd", &line[j]);
                if (line[j] == 0) {
                    cur_tomato++;
                } else if (line[j] == 1) {
                    insert_Queue(queue, i, j, h, 0);
                }
            }
            (box + R * h)[i] = line;
        }
    }
    // show_box(box, R, C, H);

    if (cur_tomato == 0) {
        printf("0");
    } else {
        bfs(box, queue, R, C, H, &colored_tomato, &longest_day);

        if (cur_tomato == colored_tomato) {
            printf("%d", longest_day);
        } else {
            printf("-1");
        }
    }

    return 0;
}

void insert_Queue(Queue* queue, int row, int col, int height, int day) {
    Coor* coor = (Coor*)malloc(sizeof(Coor));
    coor->row = row;
    coor->col = col;
    coor->height = height;
    coor->day = day;
    coor->next = NULL;

    if (queue->start == NULL) {
        queue->start = coor;
        queue->end = coor;
    } else {
        queue->end->next = coor;
        queue->end = coor;
    }
}

Coor* pop_Queue(Queue* queue) {
    if (queue->start == NULL)
        return NULL;

    Coor* coor = queue->start;
    queue->start = queue->start->next;
    if (queue->start == NULL) {
        queue->end = NULL;
    }
    return coor;
}

void bfs(short** box, Queue* queue, int R, int C, int H, int* colored_tomato, int* longest_day) {
    Coor* tile = pop_Queue(queue);
    if (tile == NULL) {
        return;
    }

    int row = tile->row;
    int col = tile->col;
    int height = tile->height;
    int day = tile->day;

    if (row > 0 && (box + R * height)[row - 1][col] == 0) { // 앞쪽
        (*colored_tomato)++;
        (box + R * height)[row - 1][col] = 1;
        insert_Queue(queue, row - 1, col, height, day + 1);

        if (*longest_day <= day + 1) {
            *longest_day = day + 1;
        }
    }
    if (row < R - 1 && (box + R * height)[row + 1][col] == 0) { // 뒤쪽
        (*colored_tomato)++;
        (box + R * height)[row + 1][col] = 1;
        insert_Queue(queue, row + 1, col, height, day + 1);

        if (*longest_day <= day + 1) {
            *longest_day = day + 1;
        }
    }
    if (col > 0 && (box + R * height)[row][col - 1] == 0) { // 왼쪽
        (*colored_tomato)++;
        (box + R * height)[row][col - 1] = 1;
        insert_Queue(queue, row, col - 1, height, day + 1);

        if (*longest_day <= day + 1) {
            *longest_day = day + 1;
        }
    }
    if (col < C - 1 && (box + R * height)[row][col + 1] == 0) { // 오른쪽
        (*colored_tomato)++;
        (box + R * height)[row][col + 1] = 1;
        insert_Queue(queue, row, col + 1, height, day + 1);

        if (*longest_day <= day + 1) {
            *longest_day = day + 1;
        }
    }
    if (height > 0 && (box + R * (height - 1))[row][col] == 0) {
        (*colored_tomato)++;
        (box + R * (height - 1))[row][col] = 1;
        insert_Queue(queue, row, col, height - 1, day + 1);

        if (*longest_day <= day + 1) {
            *longest_day = day + 1;
        }
    }
    if (height < H - 1 && (box + R * (height + 1))[row][col] == 0) {
        (*colored_tomato)++;
        (box + R * (height + 1))[row][col] = 1;
        insert_Queue(queue, row, col, height + 1, day + 1);

        if (*longest_day <= day + 1) {
            *longest_day = day + 1;
        }
    }

    // show_box(box, R, C, H);
    bfs(box, queue, R, C, H, colored_tomato, longest_day);
}

void show_box(short** box, int R, int C, int H) {
    printf("------------------------------------\n");
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if ((box + R * h)[i][j] == -1) {
                    printf("X ");
                } else if ((box + R * h)[i][j] == 0) {
                    printf("0 ");
                } else {
                    printf("1 ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}