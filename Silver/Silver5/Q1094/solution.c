#include <stdio.h>

int main() {
    int num, cnt = 0;
    scanf("%d", &num);

    if (num >= 64) {
        cnt++;
        num -= 64;
    }
    if (num >= 32) {
        cnt++;
        num -= 32;
    }
    if (num >= 16) {
        cnt++;
        num -= 16;
    }
    if (num >= 8) {
        cnt++;
        num -= 8;
    }
    if (num >= 4) {
        cnt++;
        num -= 4;
    }
    if (num >= 2) {
        cnt++;
        num -= 2;
    }
    if (num >= 1) {
        cnt++;
        num -= 1;
    }

    printf("%d", cnt);

    return 0;
}