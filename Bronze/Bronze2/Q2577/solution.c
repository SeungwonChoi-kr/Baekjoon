#include <stdio.h>

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    int array[10] = {0};

    int result = A * B * C;
    int cal = 1;
    int count = 0;

    while (result / cal != 0) {
        cal *= 10;
        count++;
    }
    cal /= 10;

    int tmp = 0;
    for (int i = 0; i < count; i++) {
        tmp = (result / cal) % 10;
        array[tmp] += 1;

        cal /= 10;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\n", array[i]);
    }
    
    return 0;
}