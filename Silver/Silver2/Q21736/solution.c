#include <stdio.h>
#include <stdlib.h>
#define MAX 602

char campus[MAX][MAX];

int lets_find_friend(char campus[MAX][MAX], int N, int M, int I_row, int I_col);
void check(int N, int M);

int main() {
    int N, M, I_row, I_col, friend_num = 0;
    char line[MAX] = {'\0'};

    scanf("%d %d", &N, &M);
    for (int i = 0; i <= MAX; i++) {
        for (int j = 0; j <= MAX; j++) {
            campus[i][j] = 'X';
        }
    }
    // check(N, M);

    for (int i = 1; i <= N; i++) {
        scanf("%s", line);
        for (int j = 1; j <= M; j++) {
            campus[i][j] = line[j - 1];
            if (campus[i][j] == 'I') {
                I_row = i;
                I_col = j;
            }
        }
    }

    friend_num = lets_find_friend(campus, N, M, I_row, I_col);
    if (friend_num > 0) {
        printf("%d", friend_num);
    } else {
        printf("TT");
    }

    return 0;
}

int lets_find_friend(char campus[MAX][MAX], int N, int M, int I_row, int I_col) {
    int friends_num = 0;
    campus[I_row][I_col] = 'X';
    // check(N, M);

    if (I_row - 1 > 0 && campus[I_row - 1][I_col] != 'X') { // 위쪽으로 이동
        if (campus[I_row - 1][I_col] == 'P') {
            friends_num++;
        }
        friends_num += lets_find_friend(campus, N, M, I_row - 1, I_col);
    }
    if (I_col - 1 > 0 && campus[I_row][I_col - 1] != 'X') { // 왼쪽으로 이동
        if (campus[I_row][I_col - 1] == 'P') {
            friends_num++;
        }
        friends_num += lets_find_friend(campus, N, M, I_row, I_col - 1);
    }
    if (I_row < N && campus[I_row + 1][I_col] != 'X') { // 아래쪽으로 이동
        if (campus[I_row + 1][I_col] == 'P') {
            friends_num++;
        }
        friends_num += lets_find_friend(campus, N, M, I_row + 1, I_col);
    }
    if (I_col < M && campus[I_row][I_col + 1] != 'X') { // 오른쪽으로 이동
        if (campus[I_row][I_col + 1] == 'P') {
            friends_num++;
        }
        friends_num += lets_find_friend(campus, N, M, I_row, I_col + 1);
    }

    return friends_num;
}

void check(int N, int M) {
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= M + 1; j++) {
            printf("%c ", campus[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
