#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(char* set, int num);
void remove1(char* set, int num);
void check(char* set, char* answer, int num);
void toggle(char* set, int num);
void all(char* set);
void empty(char* set);

int seq = 0;

int main() {
    int M;
    scanf("%d", &M);

    char func[7];
    int num;

    char* set = (char*)malloc(22 * sizeof(char));
    for (int i = 1; i <= 20; i++) {
        set[i] = '0';
    }
    char* answer = (char*)calloc(M, sizeof(char));
    seq = 0;

    for (int i = 0; i < M; i++) {
        scanf("%s", func);
        if (strcmp(func, "all") == 0) {
            all(set);
            continue;
        } else if (strcmp(func, "empty") == 0) {
            empty(set);
            continue;
        }
        scanf("%d", &num);
        getchar();

        if (strcmp(func, "add") == 0) {
            add(set, num);
        } else if (strcmp(func, "remove") == 0) {
            remove1(set, num);
        } else if (strcmp(func, "check") == 0) {
            check(set, answer, num);
        } else if (strcmp(func, "toggle") == 0) {
            toggle(set, num);
        }
    }

    seq = 0;
    while (1) {
        if (answer[seq] == '1')
            printf("1\n");
        else if (answer[seq] == '0')
            printf("0\n");
        else
            break;
        seq++;
    }

    return 0;
}

void add(char* set, int num) {
    set[num] = '1';
}

void remove1(char* set, int num) {
    set[num] = '0';
}

void check(char* set, char* answer, int num) {
    if (set[num] == '1')
        answer[seq++] = '1';
    else if (set[num] == '0')
        answer[seq++] = '0';
}

void toggle(char* set, int num) {
    if (set[num] == '1')
        set[num] = '0';
    else if (set[num] == '0')
        set[num] = '1';
}

void all(char* set) {
    for (int i = 1; i <= 20; i++)
        set[i] = '1';
}

void empty(char* set) {
    for (int i = 1; i <= 20; i++)
        set[i] = '0';
}