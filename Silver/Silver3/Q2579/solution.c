#include <stdio.h>

#define MAX(x, y) ((x) >= (y) ? (x) : (y))

int main() {
    int i, N;
    scanf("%d", &N);

    int dp[301];
    int stair[301];

    for (i = 1; i <= N; i++) {
        scanf("%d", &stair[i]);
    }

    dp[0] = 0;
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];

    for (i = 3; i <= N; i++) {
        dp[i] = stair[i] + MAX(stair[i - 1] + dp[i - 3], dp[i - 2]);
    }

    printf("%d", dp[N]);

    return 0;
}