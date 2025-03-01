#include <stdio.h>

int fac(int num) {
    int return_num = 1;
    for (int i = 1; i <= num; i++) {
        return_num *= i;
    }
    return return_num;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int result = fac(N) / (fac(N - K) * fac(K));
    printf("%d", result);
    
    return 0;
}