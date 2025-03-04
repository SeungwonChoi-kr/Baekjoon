#include <stdio.h>
#include <stdlib.h>

int main() {
    int numNum, caseNum;
    scanf("%d %d", &numNum, &caseNum);

    int* numArr = (int*)malloc((numNum + 1) * sizeof(int));
    unsigned long long* cumulationSum = (unsigned long long*)malloc((numNum + 1) * sizeof(unsigned long long));
    numArr[0] = 0;
    cumulationSum[0] = 0;
    for (int i = 1; i <= numNum; i++) {
        scanf("%d", &numArr[i]);
        cumulationSum[i] = cumulationSum[i - 1] + numArr[i];
    }

    for (int i = 0; i < caseNum; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        printf("%llu\n", cumulationSum[end] - cumulationSum[start - 1]);
    }

    return 0;
}