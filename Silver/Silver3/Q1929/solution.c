#include <stdio.h>
#include <stdlib.h>

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int* naturals = (int*)calloc(N + 1, sizeof(int));
    // 2 ~ 7까지라고 하면 7까지 저장하기 위해 크기가 8인 배열(0 ~ 7)을 만들어야 함
    naturals[0]++;
    naturals[1]++;

    for (int i = 2; i * i <= N; i++) {
        if (naturals[i] == 0) {
            for (int j = i * i; j <= N; j += i) {
                naturals[j]++;
            }
        }
    }

    for (int i = M; i <= N; i++) {
        if (naturals[i] == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}