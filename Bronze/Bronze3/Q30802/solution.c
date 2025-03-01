#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int array[6];
    int num;
    for (int i = 0; i < 6; i++) {
        scanf("%d", &num);
        array[i] = num;
    }

    int T, P;
    scanf("%d %d", &T, &P);

    int result1 = 0;
    int tmp = 0;
    for (int i = 0; i < 6; i++) {
        tmp = array[i] / T + 1;
        if (array[i] % T == 0) {
            tmp--;
        }

        result1 += tmp;
    }

    int result2_1, result2_2;

    result2_1 = N / P;
    result2_2 = N % P;

    printf("%d\n", result1);
    printf("%d %d", result2_1, result2_2);

    return 0;
}