#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    int A;

    int* array = (int*)malloc(sizeof(int) * N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &A);
        array[i] = A;
    }

    for (int i = 0; i < N; i++) {
        if (array[i] < X) {
            printf("%d ", array[i]);
        }
    }

    return 0;
}