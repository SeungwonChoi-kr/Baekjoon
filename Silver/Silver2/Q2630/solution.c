#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 128

int color_paper[MAX][MAX];

typedef struct Pair {
    int white_cnt; // 0으로 표시
    int blue_cnt;  // 1로 표시
} Pair;

Pair* counting(int row_s, int col_s, int row_e, int col_e, int size);
Pair* plus(Pair* dst, Pair* rsc);

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &color_paper[i][j]);
        }
    }
    Pair* pair = (Pair*)malloc(sizeof(Pair));
    pair = counting(0, 0, N - 1, N - 1, N);
    printf("%d\n%d", pair->white_cnt, pair->blue_cnt);

    return 0;
}

Pair* counting(int row_s, int col_s, int row_e, int col_e, int size) {
    Pair* pair = (Pair*)malloc(sizeof(Pair));
    int compare_color = color_paper[row_s][col_s]; // 사각형의 최좌상단 색 (흰:0 or 파:1)
    int goal = size * size / 2;                    // 반으로 분할하였을 때 비교해야 하는 픽셀의 총 개수 (넓이 / 2)
    int cur = 0;
    bool isOver = false;

    if (size == 2) {
        int white = 0;
        int blue = 0;
        for (int i = row_s; i <= row_e; i++) {
            for (int j = col_s; j <= col_e; j++) {
                if (color_paper[i][j] == 0) {
                    white++;
                } else {
                    blue++;
                }
            }
        }
        if (white == 0) {
            pair->blue_cnt = 1;
        } else if (blue == 0) {
            pair->white_cnt = 1;
        } else {
            pair->white_cnt = white;
            pair->blue_cnt = blue;
        }
    } else {
        int x = 0;
        for (int i = row_s; i <= row_e; i++) {
            if (isOver) {
                break;
            }

            int y = 0;
            for (int j = col_s; j <= col_e; j++) {
                if (compare_color == color_paper[i][j] && compare_color == color_paper[row_e - x][col_e - y]) {
                    y++;
                    cur++;
                    if (cur == goal) {
                        if (compare_color == 1) {
                            pair->blue_cnt++;
                        } else if (compare_color == 0) {
                            pair->white_cnt++;
                        }
                        isOver = true;
                        break;
                    }
                    continue;
                } else {
                    Pair* newPair;

                    // 왼쪽 상단
                    newPair = counting(row_s, col_s, row_e - (size / 2), col_e - (size / 2), size / 2);
                    pair = plus(pair, newPair);

                    // 오른쪽 상단
                    newPair = counting(row_s, col_e - (size / 2) + 1, row_e - (size / 2), col_e, size / 2);
                    pair = plus(pair, newPair);

                    // 왼쪽 하단
                    newPair = counting(row_e - (size / 2) + 1, col_s, row_e, col_e - (size / 2), size / 2);
                    pair = plus(pair, newPair);

                    // 오른쪽 하단
                    newPair = counting(row_e - (size / 2) + 1, col_e - (size / 2) + 1, row_e, col_e, size / 2);
                    pair = plus(pair, newPair);

                    isOver = true;
                    break;
                }
            }
            x++;
        }
    }

    return pair;
}

Pair* plus(Pair* dst, Pair* rsc) {
    dst->white_cnt += rsc->white_cnt;
    dst->blue_cnt += rsc->blue_cnt;
    return dst;
}