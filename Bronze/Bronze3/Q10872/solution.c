#include <stdio.h>

int main() {
    int N = 0;
    int result = 1;

    scanf("%d", &N);

    if (N == 0) {
        printf("%d", result);
    }
    else {
        while (N > 0) {
            result *= N;
            N--;
        }
        printf("%d", result);
    }
    
    return 0;
}