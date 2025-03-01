#include <stdio.h>

int main() {
    char students[30] = {0};
    int check = 0;

    for (int i = 0; i < 28; i++) {
        scanf("%d", &check);
        students[check - 1] = 1;
    }

    for (int i = 0; i < 30; i++)
    {
        if (students[i] == 0) {
            printf("%d ", i + 1);
        }
    }
    

    return 0;
}