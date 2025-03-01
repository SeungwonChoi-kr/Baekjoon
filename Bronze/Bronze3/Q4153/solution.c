#include <stdio.h>

void cal(int a, int b, int c) {
    int num[3];
    num[0] = a;
    num[1] = b;
    num[2] = c;

    int slide = 0;
    for (int i = 0; i < 3; i++) {
        if (num[i] > slide) {
            slide = num[i];
        }
    }

    int result = 0;

    for (int i = 0; i < 3; i++) {
        if (num[i] != slide) {
            result += num[i] * num[i];
        }
    }
    
    if (result == (slide * slide)) {
        printf("right\n");
    }
    else {
        printf("wrong\n");
    }
}

int main() {
    int num[3];
    while (scanf("%d %d %d", &num[0], &num[1], &num[2]) == 3) {
        if (num[0] * num[1] * num[2] == 0) {
            break;
        }
        cal(num[0], num[1], num[2]);
    }
    
    return 0;
}