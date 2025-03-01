#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int* array_A = (int*)malloc(sizeof(int) * N * M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", (array_A + i * M + j));
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num;
            scanf("%d", &num);

            *(array_A + i * M + j) += num;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (j != M - 1)
                printf("%d ", *(array_A + i * M + j));
            else
                printf("%d\n", *(array_A + i * M + j));
        }
    }

    return 0;
}