#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    long long int M;
    scanf("%d %lld", &N, &M);

    int tmp;
    int* arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        arr[i] = tmp;
    }

    long long int max_result = 0;
    long long int trial = 0;

    for (int a = 0; a < N - 2; a++)
    {
        for (int b = a + 1; b < N - 1; b++)
        {
            for (int c = b + 1; c < N; c++)
            {
                trial = arr[a] + arr[b] + arr[c];

                if (trial > max_result && trial <= M) {
                    max_result = trial;
                }
            }
        }
    }
    
    printf("%lld", max_result);

    return 0;
}