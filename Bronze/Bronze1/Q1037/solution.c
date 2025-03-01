#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int num;
    int min = 1000000, max = 0;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        if (min > num) {
            min = num;
        }
        if (max < num) {
            max = num;
        }
    }
    
    printf("%d", min * max);
    
    return 0;
}