#include <stdio.h>

int main() {
    int N, F;
    int cal_num = 0;

    scanf("%d", &N);
    scanf(" %d", &F);

    N = (N / 100) * 100;

    while (cal_num < N) {
        if (cal_num == N) {
            break;
        }
        cal_num += F;
    }
    
    cal_num = cal_num % 100;

    if (cal_num < 10) {
        printf("0%d\n", cal_num);
    }
    else {
        printf("%d\n", cal_num);
    }

    return 0;
}