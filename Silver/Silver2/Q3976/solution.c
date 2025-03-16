#include <stdio.h>
#include <stdlib.h>

int calculate_difficulty(int* p1p, int* p2p, int* p1d, int* p2d, int n, int l1, int l2, int s1, int s2);

int main() {
    int case_num;
    scanf("%d", &case_num);

    int n, l1, l2, s1, s2;
    int* player1_pass;
    int* player2_pass;
    int* player1_dribble;
    int* player2_dribble;
    int difficulty;

    for (int i = 0; i < case_num; i++) {
        scanf("%d %d %d %d %d", &n, &l1, &l2, &s1, &s2);
        player1_pass = (int*)malloc((n - 1) * sizeof(int));
        player2_pass = (int*)malloc((n - 1) * sizeof(int));
        player1_dribble = (int*)malloc((n - 1) * sizeof(int));
        player2_dribble = (int*)malloc((n - 1) * sizeof(int));

        for (int j = 0; j < n - 1; j++) {
            scanf("%d", &player1_pass[j]);
        }
        for (int j = 0; j < n - 1; j++) {
            scanf("%d", &player1_dribble[j]);
        }
        for (int j = 0; j < n - 1; j++) {
            scanf("%d", &player2_pass[j]);
        }
        for (int j = 0; j < n - 1; j++) {
            scanf("%d", &player2_dribble[j]);
        }

        difficulty = calculate_difficulty(player1_pass, player2_pass, player1_dribble, player2_dribble, n, l1, l2, s1, s2);
        printf("%d\n", difficulty);
    }

    return 0;
}

int calculate_difficulty(int* p1p, int* p2p, int* p1d, int* p2d, int n, int l1, int l2, int s1, int s2) {
    int* p1_cumulative = (int*)malloc((n + 1) * sizeof(int));
    int* p2_cumulative = (int*)malloc((n + 1) * sizeof(int));
    p1_cumulative[0] = l1;
    p2_cumulative[0] = l2;

    int tmp_case1 = 0;
    int tmp_case2 = 0;
    int result = 0;

    for (int i = 0; i < n - 1; i++) {
        // player1이 다음 지점에 갈 때, 난이도 계산
        tmp_case1 = p2_cumulative[i] + p2p[i]; // 다음 지점으로 패스를 받거나 (p2가 고생하고 패스까지)
        tmp_case2 = p1_cumulative[i] + p1d[i]; // 다음 지점까지 드리블을 하거나 (p1이 고생하고 드리블까지)
        p1_cumulative[i + 1] = (tmp_case1 < tmp_case2) ? tmp_case1 : tmp_case2;

        // player2가 다음 지점에 갈 때, 난이도 계산
        tmp_case1 = p1_cumulative[i] + p1p[i]; // 다음 지점으로 패스를 받거나 (p1이 고생하고 패스까지)
        tmp_case2 = p2_cumulative[i] + p2d[i]; // 다음 지점까지 드리블을 하거나 (p2가 고생하고 드리블까지)
        p2_cumulative[i + 1] = (tmp_case1 < tmp_case2) ? tmp_case1 : tmp_case2;
    }
    p1_cumulative[n] = p1_cumulative[n - 1] + s1;
    p2_cumulative[n] = p2_cumulative[n - 1] + s2;
    result = (p1_cumulative[n] < p2_cumulative[n]) ? p1_cumulative[n] : p2_cumulative[n];

    return result;
}
