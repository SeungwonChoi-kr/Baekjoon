#include <stdio.h>

int map[1001][1001];
int dp[1001][1001];

int min(int a, int b, int c);

int main() {
    int n, m;
    char line[1001];
    int max = 0;

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", line);
        for (int j = 1; j <= m; j++) {
            map[i][j] = line[j - 1] - '0';
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == 0) {
                continue;
            }

            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1;

            if (max < dp[i][j]) {
                max = dp[i][j];
            }
        }
    }
    printf("%d", max * max);

    return 0;
}

int min(int a, int b, int c) {
    // printf("%d %d %d\n", a, b, c);
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}
