#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int* array = (int*)malloc(sizeof(int) * N);
    
    int A;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A);
        array[i] = A;
    }

    int V;
    scanf("%d", &V);
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (array[i] == V)
            count++;
    }

    printf("%d", count);
    
    return 0;
}