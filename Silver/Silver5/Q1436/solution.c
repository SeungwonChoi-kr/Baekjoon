#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    int search = 1;

    for (int i = 666; i < 2666800; i++) {
        char num[8] = {'\0'};
        sprintf(num, "%d", i);

        if (strstr(num, "666")) {
            if (N == search) {
                printf("%s", num);
                break;
            }
            else {
                search++;
            }
        }
    }

    return 0;
}