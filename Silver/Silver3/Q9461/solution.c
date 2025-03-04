#include <stdio.h>

int main() {
    int caseNum, idx;
    scanf("%d", &caseNum);

    unsigned long long numArr[101] = {
        0,
    };
    // 초기화
    numArr[1] = 1;
    numArr[2] = 1;
    numArr[3] = 1;
    numArr[4] = 2;
    numArr[5] = 2;
    numArr[6] = 3;

    for (int i = 0; i < caseNum; i++) {
        int N;
        scanf("%d", &N);

        idx = 6;
        while (idx <= N) {
            if (numArr[idx] == 0) {
                numArr[idx] = numArr[idx - 1] + numArr[idx - 5];
            }
            idx++;
        }
        printf("%llu\n", numArr[N]);
    }

    return 0;
}