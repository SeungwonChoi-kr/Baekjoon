#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
    char line[100];
    int word_len;
    bool isHiPon = false;

    scanf("%[^\n]s", line);
    word_len = strlen(line);

    for (int i = 0; i < word_len; i++) {
        if (line[i] != '(' && line[i] != ')') {
            printf("%c", line[i]);
        } else {
            if (line[i] == '(') {
                printf("\n");
            }

            isHiPon = true;
        }
    }

    if (!isHiPon) {
        printf("\n-");
    }

    return 0;
}