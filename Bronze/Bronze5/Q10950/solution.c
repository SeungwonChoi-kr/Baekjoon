#include <stdio.h>
#include <stdlib.h>

int main() {
    int T = 0;
    int A = 0, B = 0;

    scanf("%d", &T);

    int* results = (int*)malloc(sizeof(int) * T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &A, &B);
        results[i] = A + B;
    }

    for (int i = 0; i < T; i++)
    {
        printf("%d\n", results[i]);
    }
    

    return 0;
}