#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int R;
        scanf("%d", &R);

        char line[20];
        scanf("%s", line);

        int length = strlen(line);
        
        for (int j = 0; j < length; j++) {
            for (int k = 0; k < R; k++) {
                printf("%c", line[j]);
            }
        }
        printf("\n");
    }

    return 0;
}