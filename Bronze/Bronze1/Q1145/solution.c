#include <stdio.h>
#include <stdlib.h>

void looping(int* naturalNum);
int minimal_num(int a, int b, int c);
int* calc_primes(int num, int* primes);

int main() {
    int naturalNum[5];

    for (int i = 0; i < 5; i++) {
        scanf("%d", &naturalNum[i]);
    }

    looping(naturalNum);

    return 0;
}

void looping(int* naturalNum) {
    int results[10] = {0};
    int loop = 0;
    int minimalNum = 1000000;

    for (int num1 = 0; num1 < 3; num1++) {
        for (int num2 = num1 + 1; num2 < 4; num2++) {
            for (int num3 = num2 + 1; num3 < 5; num3++) {
                results[loop++] = minimal_num(naturalNum[num1], naturalNum[num2], naturalNum[num3]);
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        if (results[i] < minimalNum) {
            minimalNum = results[i];
        }
    }

    printf("%d", minimalNum);
}

int minimal_num(int a, int b, int c) {
    int div;
    int result = 1;

    int* a_primes = (int*)calloc(101, sizeof(int));
    int* b_primes = (int*)calloc(101, sizeof(int));
    int* c_primes = (int*)calloc(101, sizeof(int));

    a_primes = calc_primes(a, a_primes);
    b_primes = calc_primes(b, b_primes);
    c_primes = calc_primes(c, c_primes);

    for (int i = 2; i <= 100; i++) {
        int tmp_prime = 0;

        if (a_primes[i] > tmp_prime) {
            tmp_prime = a_primes[i];
        }
        if (b_primes[i] > tmp_prime) {
            tmp_prime = b_primes[i];
        }
        if (c_primes[i] > tmp_prime) {
            tmp_prime = c_primes[i];
        }

        for (int j = 0; j < tmp_prime; j++) {
            result *= i;
        }
    }

    return result;
}

int* calc_primes(int num, int* primes) {
    int div = 2;

    while (num != 1) {
        if (num % div == 0) {
            num = num / div;
            primes[div]++;
        }
        else {
            div++;
        }
    }

    return primes;
}