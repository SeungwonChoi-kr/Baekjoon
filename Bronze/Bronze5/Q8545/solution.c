#include <stdio.h>

int main() {
    char word[4];
    scanf("%s", word);

    printf("%c%c%c", word[2], word[1], word[0]);

    return 0;
}