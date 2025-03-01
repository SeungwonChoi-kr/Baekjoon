#include <stdio.h>

int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    printf("%d\n", A + B - C);

    int cnt = 1;
    while ((B / cnt) != 0) {
        cnt *= 10;
    }
    
    printf("%d", cnt * A + B - C);

    return 0;
}