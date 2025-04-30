#include <stdio.h>
#include <stdlib.h>

long long MAX(long long X, long long Y) {
    if (X > Y)
        return X;
    else
        return Y;
}
long long MIN(long long X, long long Y) {
    if (X < Y)
        return X;
    else
        return Y;
}
long long divide_and_find_max(int* height, long long s, long long e);
long long find_mid_max(int* height, long long s, long long m, long long e);

int main() {
    long long N;
    scanf("%lld", &N);

    while (N != 0) {
        int* height = (int*)malloc(N * sizeof(int));
        for (long long i = 0; i < N; i++) {
            scanf("%d", &height[i]);
        }
        printf("%lld\n", divide_and_find_max(height, 0, N - 1));
        free(height);
        scanf("%lld", &N);
    }

    return 0;
}

long long divide_and_find_max(int* height, long long s, long long e) {
    if (s == e) {
        return height[s];
    }

    long long m = (s + e) / 2;
    long long left_right_max = MAX(divide_and_find_max(height, s, m), divide_and_find_max(height, m + 1, e));
    long long mid_max = find_mid_max(height, s, m, e);

    // printf("[%d~%d]mid_max = %d, lr_max = %d\n", s, e, mid_max, left_right_max);
    return MAX(mid_max, left_right_max);
}

long long find_mid_max(int* height, long long s, long long m, long long e) {
    long long low = m, high = m + 1;
    int cur_height = MIN(height[low], height[high]);
    long long mid_max_size = 2 * cur_height;

    // 일단 적어도 둘 중 하나는 끝에 도달하지 않음
    while (low > s || high < e) {
        if (low == s) { // 왼쪽은 끝났다면
            cur_height = MIN(cur_height, height[++high]);
        } else if (high == e) { // 오른쪽이 끝났다면
            cur_height = MIN(cur_height, height[--low]);
        } else {
            if (height[low - 1] >= height[high + 1]) {
                cur_height = MIN(cur_height, height[--low]);
            } else {
                cur_height = MIN(cur_height, height[++high]);
            }
        }

        mid_max_size = MAX(mid_max_size, cur_height * (high - low + 1));
        // printf("mid_max_size: %d\n", mid_max_size);
    }

    return mid_max_size;
}