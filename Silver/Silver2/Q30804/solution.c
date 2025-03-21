#include <stdio.h>
#include <stdlib.h>
#define bigger(X, Y) ((X) > (Y) ? (X) : (Y))

int main() {
    int N, result = 0, total_cnt, one_type_cnt, pre_fruit_type, other_fruit_type = 0;
    int* stick;
    scanf("%d", &N);
    stick = (int*)calloc(N, sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &stick[i]);
    }

    total_cnt = 1;
    one_type_cnt = 1;
    pre_fruit_type = stick[0];
    for (int i = 1; i < N; i++) {
        result = bigger(result, total_cnt);
        if (stick[i] == pre_fruit_type) {
            total_cnt++;
            one_type_cnt++;
        } else if (stick[i] != pre_fruit_type) {
            if (stick[i] == other_fruit_type) {
                total_cnt++;
            } else if (stick[i] != other_fruit_type) {
                total_cnt = one_type_cnt + 1;
            }
            one_type_cnt = 1;
            other_fruit_type = pre_fruit_type;
            pre_fruit_type = stick[i];
        }
    }
    result = bigger(result, total_cnt);
    printf("%d", result);

    return 0;
}