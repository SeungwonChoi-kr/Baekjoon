#include <stdio.h>
#include <stdlib.h>

int calculator(int coin_type, int balance, int* coin_num);

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int coin_num = 0;
    int* coins = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &coins[i]);
    }

    for (int i = N - 1; i >= 0; i--) {
        K = calculator(coins[i], K, &coin_num);
    }

    printf("%d\n", coin_num);

    return 0;
}

int calculator(int coin_type, int balance, int* coin_num) {
    while (coin_type <= balance) {
        balance -= coin_type;
        *coin_num += 1;
    }

    return balance;
}