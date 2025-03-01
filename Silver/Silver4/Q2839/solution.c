#include <stdio.h>
#include <stdlib.h>

int packaging(int kg);

int main() {
    int bags;
    int N;
    scanf("%d", &N);

    bags = packaging(N);

    printf("%d", bags);

    return 0;
}

int packaging(int kg) {
    int tmp_bags = 100000;

    int loop = kg / 3 + 1;

    int* results = (int*)calloc(loop, sizeof(int));
    for (int i = 0; i < loop; i++) {
        int tmp_kg = kg - 3 * i;

        if (tmp_kg % 5 == 0) {
            results[i] = i + tmp_kg / 5;
        }
        else {
            results[i] = -1;
        }
    }

    for (int i = 0; i < loop; i++) {
        if (results[i] != -1 && results[i] < tmp_bags) {
            tmp_bags = results[i];
        }
    }

    if (tmp_bags == 100000) {
        tmp_bags = -1;
    }

    return tmp_bags;
}