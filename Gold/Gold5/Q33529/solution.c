#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char*** bingo = (char***)calloc(n, sizeof(char**));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            char* line = (char*)malloc(sizeof(char));
        }
    }

    return 0;
}