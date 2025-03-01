#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Pairs {
    int x;
    int y;
} Pairs;

int main() {
    int N, K;
    scanf("%d", &N);
    scanf("%d", &K);

    Pairs** pairs = (Pairs**)malloc(K * sizeof(Pairs*));
    for (int i = 0; i < K; i++) {
        Pairs* pair = (Pairs*)malloc(sizeof(Pairs));
        scanf("%d %d", &pair->x, &pair->y);
        pairs[i] = pair;
    }

    bool* pc = (bool*)calloc(N + 1, sizeof(bool));
    pc[1] = 1;
    int capture[101] = {0};
    int cnt = 0;
    int a = 0;

    for (int i = 0; i < K; i++) {
        if (pairs[i]->x == 1) {
            capture[a++] = pairs[i]->y;
            pc[pairs[i]->y] = 1;
            cnt++;
        }
        if (pairs[i]->y == 1) {
            capture[a++] = pairs[i]->x;
            pc[pairs[i]->x] = 1;
            cnt++;
        }
    }

    int n = 0;
    while (capture[n] != 0) {
        for (int i = 0; i < K; i++) {
            if (pairs[i]->x == capture[n]) {
                if (pc[pairs[i]->y] == 0) {
                    capture[a++] = pairs[i]->y;
                    pc[pairs[i]->y] = 1;
                    cnt++;
                }
            }
            if (pairs[i]->y == capture[n]) {
                if (pc[pairs[i]->x] == 0) {
                    capture[a++] = pairs[i]->x;
                    pc[pairs[i]->x] = 1;
                    cnt++;
                }
            }
        }
        n++;
    }

    printf("%d", cnt);

    return 0;
}