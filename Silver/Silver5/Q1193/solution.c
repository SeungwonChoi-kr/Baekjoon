/* 분수찾기 */
#include <stdio.h>

int main() {
    int X, i = 0, sum = 0;
    scanf("%d", &X);

    while (sum < X) {
        i++;
        sum += i;
    }
    // 여기서 나오는 i는 분자와 분모를 더했을 때의 값이다
    sum = sum - i;
    i++;

    int son, mom;
    int cnt = X - sum - 1;
    if ((i - 1) % 2 == 0) {
        son = 1;
        mom = i - 1;
        for (int k = 0; k < cnt; k++) {
            son++;
            mom--;
        }
    } else {
        son = i - 1;
        mom = 1;
        for (int k = 0; k < cnt; k++) {
            son--;
            mom++;
        }
    }

    printf("%d/%d\n", son, mom);

    return 0;
}