#include <stdio.h>
#include <stdlib.h>

int main() {
    char tile = '\0';
    int cnt = 0;

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            scanf("%c", &tile);

            if ((row + col) % 2 == 0) {
                if (tile == 'F') {
                    cnt++;
                }
            }
        }
        getchar();
    }

    printf("%d", cnt);

    return 0;
}