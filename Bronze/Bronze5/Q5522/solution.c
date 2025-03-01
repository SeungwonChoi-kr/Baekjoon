#include <stdio.h>

int main() {
    int scores[5];

    for (int i = 0; i < 5; i++) {
        scanf("%d", &scores[i]);
    }

    printf("%d", scores[0] + scores[1] + scores[2] + scores[3] + scores[4]);

    return 0;
}