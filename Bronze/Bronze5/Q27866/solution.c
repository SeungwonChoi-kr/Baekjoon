#include <stdio.h>

int main() {
    char line[1000];
    scanf("%s", line);

    int idx;
    scanf("%d", &idx);

    printf("%c", line[idx - 1]);

    return 0;
}