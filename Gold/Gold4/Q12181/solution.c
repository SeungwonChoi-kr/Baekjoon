#include <stdio.h>
#define MAX 26

long dp[MAX][MAX] = {0}; // 0도 있지만 무시, 1부터 25까지

long acting(int R, int C);
void check() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%ld ", dp[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int T, R, C;
    scanf("%d", &T);

    for (int x = 1; x < MAX; x++) {
        dp[x][0] = 1;
        dp[x][1] = 1;
        dp[0][x] = 1;
        dp[1][x] = 1;
    }

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &R, &C);
        printf("Case #%d: %ld\n", i  + 1, acting(R, C));
        // check();
    }

    return 0;
}

long acting(int R, int C) {
    if (dp[R][C] == 0) {
        dp[R][C] = acting(R - 1, C) + acting(R, C - 1);
    }
    return dp[R][C];
}
