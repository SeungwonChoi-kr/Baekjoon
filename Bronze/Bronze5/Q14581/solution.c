#include <stdio.h>

int main() {
    char name[21];
    scanf("%s", name);

    for (int i = 0; i < 3; i++) {
        printf(":fan:");
    }
    printf("\n");

    printf(":fan::%s::fan:\n", name);

    for (int i = 0; i < 3; i++) {
        printf(":fan:");
    }

    return 0;
}