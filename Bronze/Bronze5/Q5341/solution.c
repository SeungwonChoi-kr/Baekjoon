#include <stdio.h>

int main() {
    int input = 0;
    int sum = 0;

    while (1) {
        scanf("%d", &input);

        if (input == 0) {
            break;
        }

        for (int i = 1; i <= input; i++) {
            sum += i;
        }

        printf("%d\n", sum);
        sum = 0;
    }

    return 0;
}