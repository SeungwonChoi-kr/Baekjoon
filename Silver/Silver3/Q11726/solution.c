#include <stdio.h>
#include <stdlib.h>

int fibonacci(int* fibonacciArr, int n);

int main() {
    int n;
    scanf("%d", &n);

    int* fibonacciArr = (int*)calloc(n + 1, sizeof(int));
    fibonacciArr[0] = 1;
    fibonacciArr[1] = 1;
    fibonacci(fibonacciArr, n);

    printf("%d", fibonacciArr[n]);

    return 0;
}

int fibonacci(int* fibonacciArr, int n) {
    if (fibonacciArr[n] == 0) {
        fibonacciArr[n] = fibonacci(fibonacciArr, n - 1) + fibonacci(fibonacciArr, n - 2);
        fibonacciArr[n] %= 10007;
    }
    return fibonacciArr[n];
}