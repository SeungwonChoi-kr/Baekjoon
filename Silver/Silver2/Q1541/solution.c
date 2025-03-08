#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51

int main() {
    char exp[MAX];
    scanf("%s", exp);

    int length = strlen(exp);
    int idx = 0;
    int sum = atoi(&exp[idx]);
    int minus_sum = 0;
    int tmp_sum = 0;

    while (exp[idx] != '+' && exp[idx] != '-') {
        idx++;
    }

    while (idx < length) {
        if (exp[idx] == '-') {
            idx++;
            minus_sum += atoi(&exp[idx]);
            while (exp[idx] != '+' && exp[idx] != '-') {
                idx++;
            }
        } else {
            idx++;
            tmp_sum = atoi(&exp[idx]);
            while (exp[idx] != '+' && exp[idx] != '-') {
                idx++;
            }

            if (minus_sum == 0) {
                sum += tmp_sum;
            } else {
                minus_sum += tmp_sum;
            }
        }

        tmp_sum = 0;
    }
    printf("%d", sum - minus_sum);

    return 0;
}