#include <stdio.h>

int check_2(int num) {
    int two_cnt = 0;

    if (num == 0) {
        return 0;
    }

    while (1) {
        if (num % 2 == 0) {
            num /= 2;
            two_cnt++;
        }
        else {
            break;
        }
    }
    
    return two_cnt;
}

int check_5(int num) {
    int five_cnt = 0;

    if (num == 0) {
        return 0;
    }

    while (1) {
        if (num % 5 == 0) {
            num /= 5;
            five_cnt++;
        }
        else {
            break;
        }
    }
    
    return five_cnt;
}

int main() {
    int N;
    scanf("%d", &N);

    int two_cnt = 0, five_cnt = 0;

    for (int i = 0; i <= N; i++) {
        two_cnt += check_2(i);
        five_cnt += check_5(i);
    }

    if (two_cnt == five_cnt) {
        printf("%d", two_cnt);
    }
    else if (two_cnt > five_cnt) {
        printf("%d", five_cnt);
    }
    else {
        printf("%d", two_cnt);
    }

    return 0;
}