#include <stdio.h>

long long combine(int N, int M);

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N, M;
        scanf("%d %d", &N, &M);

        printf("%llu\n", combine(M, N));
    }

    return 0;
}

long long combine(int N, int M) {
    long long sum = 1;

    if (N - M > M) {
        for (int i = N; i > N - M; i--) {
            sum *= i;
        }

        for (int i = M; i > 1; i--) {
            sum /= i;
        }
    }
    else {
        for (int i = N; i > M; i--) {
            sum *= i;
        }

        for (int i = N - M; i > 1; i--) {
            sum /= i;
        }
    }

    return sum;
}