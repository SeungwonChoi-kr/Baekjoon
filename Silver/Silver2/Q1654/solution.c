#include <stdio.h>
#include <stdlib.h>

unsigned cutting(unsigned* LAN_cables, int K, int N);

int main() {
    int K, N;
    scanf("%d %d", &K, &N);

    unsigned* LAN_cables = (unsigned*)malloc(K * sizeof(unsigned));
    for (int i = 0; i < K; i++) {
        scanf("%u", &LAN_cables[i]);
    }
    printf("%u", cutting(LAN_cables, K, N));

    return 0;
}

unsigned cutting(unsigned* LAN_cables, int K, int N) {
    unsigned long long start = 0;
    unsigned long long end = 2147483648;
    unsigned long long middle = 0;
    unsigned long long LAN_cnt = 0;

    while (start + 1 < end) {
        LAN_cnt = 0;
        middle = (start + end) / 2;

        for (int i = 0; i < K; i++) {
            LAN_cnt += LAN_cables[i] / middle;
        }

        if (LAN_cnt >= N) {
            start = middle;
        } else if (LAN_cnt < N) {
            end = middle;
        }
    }

    return end - 1;
}