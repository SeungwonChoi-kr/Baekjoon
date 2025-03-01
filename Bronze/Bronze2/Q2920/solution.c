#include <stdio.h>

int main() {
    int array[8];
    for (int i = 0; i < 8; i++)
    {
        scanf("%d", &array[i]);
    }

    int isDescending = 0;
    int isAscending = 0;

    if (array[0] == 8) {
        isDescending = 1;
        for (int i = 0; i < 8; i++) {
            if (array[i] != (8 - i)) {
                isDescending = 0;
                break;
            }
        }
    }
    else if (array[0] == 1) {
        isAscending = 1;
        for (int i = 0; i < 8; i++) {
            if (array[i] != (i + 1)) {
                isAscending = 0;
                break;
            }
        }
    }

    if (isAscending) {
        printf("ascending");
    }
    else if (isDescending) {
        printf("descending");
    }
    else {
        printf("mixed");
    }
    
    return 0;
}