#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    char line[100];
    scanf("%s", line);

    int result = 0;
    
    for (int i = 0; i < N; i++) {
        result += line[i] - '0';
    }
    printf("%d", result);

    return 0;
}