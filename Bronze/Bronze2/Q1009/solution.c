#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    
    int* results = (int*)malloc(sizeof(int) * T);
    
    for (int i = 0; i < T; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        results[i] = 1;
        for (int j = 0; j < b; j++) {
            results[i] = (a * results[i]) % 10;
        }
    }
    
    for (int i = 0; i < T; i++)
        printf("%d\n", results[i]);
    
    free(results);
    
    return 0;
}