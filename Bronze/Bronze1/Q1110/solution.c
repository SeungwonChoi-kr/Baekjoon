#include <stdio.h>

int main() {
    int N;
    int prev_num;
    int count = 0;

    scanf("%d", &N);
    prev_num = N;

    while (1) {
        int numA = prev_num;
        int sum;
        int numB;

        if (numA < 10) {
            sum = numA;
        }
        else {
            sum = numA / 10 + numA % 10;
        }

        count++;
        numB = (numA % 10) * 10 + (sum % 10);

        if (numB == N)
        {
            printf("%d", count);
            break;
        }
        else {
            prev_num = numB;
        }
    }

    return 0;
}