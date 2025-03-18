#include <stdio.h>
#include <string.h>

int main() {
    char string[32];
    int N;
    scanf("%s", string);
    scanf("%d", &N);
    int sum = 0, i = 0;

    while (string[i] != '\0') {
        if (string[i] >= '0' && string[i] <= '9') {
            sum = sum * N + (string[i] - '0');
        } else {
            sum = sum * N + (string[i] - 'A' + 10);
        }
        i++;
    }

    printf("%d", sum);

    return 0;
}