#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int i = 1;
    int comb[11] = {0};
    comb[1] = 1; // 1
    comb[2] = 2; // 1 + 1 | 2
    comb[3] = 4; // 1 + 1 + 1 | 1 + 2 | 2 + 1 | 3
    while (i <= 10) {
        if (comb[i] == 0) {
            comb[i] = comb[i - 1] + comb[i - 2] + comb[i - 3];
        }
        i++;
    }

    for (int i = 0; i < T; i++) {
        int num;
        scanf("%d", &num);

        printf("%d\n", comb[num]);
    }

    return 0;
}