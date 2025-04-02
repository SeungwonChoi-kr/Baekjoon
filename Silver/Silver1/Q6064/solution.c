/* 카잉 달력 */
#include <stdbool.h>
#include <stdio.h>

void caIn_Calendar(int M, int N, int x, int y);

int main() {
    int case_num, M, N, x, y;
    scanf("%d", &case_num);

    for (int i = 0; i < case_num; i++) {
        scanf("%d %d %d %d", &M, &N, &x, &y);
        caIn_Calendar(M, N, x, y);
    }

    return 0;
}

void caIn_Calendar(int M, int N, int x, int y) {
    bool isLoop = false;
    int cnt, tmp = 0, start_of_x, start_of_y;

    if (M < N) {
        cnt = x;
        start_of_y = cnt % N;
        if (start_of_y == 0) {
            start_of_y = N;
        }

        if (start_of_y == y) {
            printf("%d\n", cnt);
            isLoop = true;
        } else {
            cnt += M;
        }

        while (!isLoop && start_of_y != tmp) {
            tmp = cnt % N;
            if (tmp == 0) {
                tmp = N;
            }

            if (tmp == y) {
                printf("%d\n", cnt);
                isLoop = true;
            } else {
                cnt += M;
            }
        }
    } else {
        cnt = y;
        start_of_x = cnt % M;
        if (start_of_x == 0) {
            start_of_x = M;
        }

        if (start_of_x == x) {
            printf("%d\n", cnt);
            isLoop = true;
        } else {
            cnt += N;
        }

        while (!isLoop && start_of_x != tmp) {
            tmp = cnt % M;
            if (tmp == 0) {
                tmp = M;
            }

            if (tmp == x) {
                printf("%d\n", cnt);
                isLoop = true;
            } else {
                cnt += N;
            }
        }
    }

    if (!isLoop) {
        printf("-1\n");
    }
}