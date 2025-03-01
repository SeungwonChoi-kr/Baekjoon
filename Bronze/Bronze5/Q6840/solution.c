#include <stdio.h>

int main() {
    int plate[3];
    int max = 0;
    int min = 100;

    for (int i = 0; i < 3; i++) {
        scanf("%d", &plate[i]);
    }

    for (int i = 0; i < 3; i++) {
        if (plate[i] > max) {
            max = plate[i];
        }

        if (plate[i] < min) {
            min = plate[i];
        }
    }

    for (int i = 0; i < 3; i++) {
        if (plate[i] != max && plate[i] != min) {
            printf("%d", plate[i]);
            break;
        }
    }

    return 0;
}