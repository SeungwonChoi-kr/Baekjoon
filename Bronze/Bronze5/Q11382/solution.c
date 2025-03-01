#include <stdio.h>

int main() {
    long long A = 1, B = 1, C = 1;

    scanf("%lld %lld %lld", &A, &B, &C);

    long long sum;
    sum = A + B + C;
    printf("%lld\n", sum);

    return 0;
}