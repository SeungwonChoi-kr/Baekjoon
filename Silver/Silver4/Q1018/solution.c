#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void coloring(char** board, int N, int M);
int comparing(char start_color, char target_color);

int main() {
    int N, M;
    char** board;

    scanf("%d %d", &N, &M);

    board = (char**)malloc(sizeof(char*) * N);

    for (int i = 0; i < N; i++) {
        board[i] = (char*)malloc(sizeof(char) * (M + 1));
    }

    for (int i = 0; i < N; i++) {
        scanf("%s", board[i]);
    }

    coloring(board, N, M);

    return 0;
}

void coloring(char** board, int N, int M) {
    int loop_time = (N - 8 + 1) * (M - 8 + 1);
    int loop = 0;
    int smallest_attempt = 2500;
    int* results = (int*)malloc(2 * loop_time * sizeof(int));

    while (loop < loop_time) {
        int start_row = loop / (M - 8 + 1);
        int start_col = loop % (M - 8 + 1);
        char start_color = board[start_row][start_col];
        char second_color;

        if (start_color == 'B') {
            second_color = 'W';
        }
        else if (start_color == 'W') {
            second_color = 'B';
        }

        if ((start_row + start_col) % 2 == 0) {
            for (int i = start_row; i < start_row + 8; i++) {
                for (int j = start_col; j < start_col + 8; j++) {
                    if ((i + j) % 2 == 0) {
                        results[loop] += comparing(start_color, board[i][j]);
                    }
                    else {
                        results[loop] += comparing(second_color, board[i][j]);
                    }
                }
            }
        }
        else {
            for (int i = start_row; i < start_row + 8; i++) {
                for (int j = start_col; j < start_col + 8; j++) {
                    if ((i + j) % 2 == 1) {
                        results[loop] += comparing(start_color, board[i][j]);
                    }
                    else {
                        results[loop] += comparing(second_color, board[i][j]);
                    }
                }
            }
        }

        loop++;
    }

    int second_loop = loop;

    while (loop < 2 * loop_time) {
        int start_row = (loop - second_loop) / (M - 8 + 1);
        int start_col = (loop - second_loop) % (M - 8 + 1);
        char start_color;
        char second_color = board[start_row][start_col];

        if (second_color == 'B') {
            start_color = 'W';
        }
        else if (second_color == 'W') {
            start_color = 'B';
        }

        if ((start_row + start_col) % 2 == 0) {
            for (int i = start_row; i < start_row + 8; i++) {
                for (int j = start_col; j < start_col + 8; j++) {
                    if ((i + j) % 2 == 0) {
                        results[loop] += comparing(start_color, board[i][j]);
                    }
                    else {
                        results[loop] += comparing(second_color, board[i][j]);
                    }
                }
            }
        }
        else {
            for (int i = start_row; i < start_row + 8; i++) {
                for (int j = start_col; j < start_col + 8; j++) {
                    if ((i + j) % 2 == 1) {
                        results[loop] += comparing(start_color, board[i][j]);
                    }
                    else {
                        results[loop] += comparing(second_color, board[i][j]);
                    }
                }
            }
        }

        loop++;
    }

    for (int i = 0; i < 2 * loop_time; i++) {
        if (results[i] < smallest_attempt) {
            smallest_attempt = results[i];
        }
    }

    printf("%d", smallest_attempt);
}

int comparing(char start_color, char target_color) {
    if (start_color == target_color) {
        return 0;
    }
    else {
        return 1;
    }
}