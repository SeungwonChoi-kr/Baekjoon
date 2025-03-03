#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    int clothNum;
    char clothName[21];
    char* clothType;
    char* clothArr[30];
    int numArr[30] = {
        0,
    };

    for (int i = 0; i < T; i++) {
        int arrNum = 0;
        int sum = 1;

        scanf("%d", &clothNum);
        for (int j = 0; j < clothNum; j++) {
            bool isAdded = false;

            scanf("%s", clothName);
            clothType = (char*)malloc(21 * sizeof(char));
            scanf("%s", clothType);

            for (int k = 0; k < arrNum; k++) {
                if (strcmp(clothArr[k], clothType) == 0) {
                    numArr[k]++;
                    isAdded = true;
                    break;
                }
            }

            if (!isAdded) {
                clothArr[arrNum] = clothType;
                numArr[arrNum] = 1;
                arrNum++;
            }
        }

        for (int j = 0; j < arrNum; j++) {
            sum *= (numArr[j] + 1);
        }
        printf("%d\n", sum - 1);
    }

    return 0;
}