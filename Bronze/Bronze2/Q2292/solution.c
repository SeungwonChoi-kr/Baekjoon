#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int distance = 1;
    int section = 1;

    while (1) {
        section += 6 * (distance - 1);
        
        if (N <= section) {
            printf("%d", distance);
            break;
        }
        else {
            distance++;
        }
    }

    return 0;
}