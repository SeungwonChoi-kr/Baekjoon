#include <stdio.h>
#include <stdlib.h>

int function(int* count, unsigned N);

int main() {
    unsigned N;
    scanf("%u", &N);

    int* count = (int*)calloc(N + 1, sizeof(int));
    count[0] = -1;
    count[1] = 0;
    count[2] = 1;
    count[3] = 1;

    function(count, N);
    printf("%d", count[N]);

    return 0;
}

int function(int* count, unsigned N) {
    int cnt = 1000000;
    int cases[3] = {0};

    if (N > 3) {
        // 2로 나누기
        if (N % 2 == 0) {
            cases[0]++;
            if (count[N / 2] == 0) {
                cases[0] += function(count, N / 2);
                count[N / 2] = cases[0];
            } else {
                cases[0] += count[N / 2];
            }
        }
        // 3으로 나누기
        if (N % 3 == 0) {
            cases[1]++;
            if (count[N / 3] == 0) {
                cases[1] += function(count, N / 3);
                count[N / 3] = cases[1];
            } else {
                cases[1] += count[N / 3];
            }
        }
        // 1 빼기
        cases[2]++;
        cases[2] += function(count, N - 1);

        for (int i = 0; i < 3; i++) {
            if (cnt > cases[i] && cases[i] != 0) {
                cnt = cases[i];
            }
        }
        count[N] = cnt;
    }

    return cnt;
}