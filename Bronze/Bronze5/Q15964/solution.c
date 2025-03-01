#include <stdio.h>

void func(long long int a, long long int b) {
    printf("%lld", (a + b) * (a - b));
}

int main() {
    long long int a, b;
    scanf("%lld %lld", &a, &b);

    func(a, b);

    return 0;
}