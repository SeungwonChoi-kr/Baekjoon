#include <stdio.h>
#include <string.h>

int map[50][50], m, n;

void dfs(int x, int y);

int main() {
    int caseNum;
    scanf("%d", &caseNum);

    int x, y, cabbageNum, worm_cnt;
    for (int cs = 0; cs < caseNum; cs++) {
        memset(map, 0, sizeof(map));
        scanf("%d %d %d", &m, &n, &cabbageNum);

        for (int i = 0; i < cabbageNum; i++) {
            scanf("%d %d", &x, &y);
            map[x][y] = 1;
        }

        worm_cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 1) {
                    dfs(i, j);
                    worm_cnt++;
                }
            }
        }
        printf("%d\n", worm_cnt);
    }

    return 0;
}

void dfs(int x, int y) {
    map[x][y] = 0;
    if (x > 0 && map[x - 1][y] == 1) dfs(x - 1, y);
    if (x + 1 < m && map[x + 1][y] == 1) dfs(x + 1, y);
    if (y > 0 && map[x][y - 1] == 1) dfs(x, y - 1);
    if (y + 1 < n && map[x][y + 1] == 1) dfs(x, y + 1);
}