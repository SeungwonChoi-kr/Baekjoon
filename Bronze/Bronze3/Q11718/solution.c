#include <stdio.h>
#include <string.h>

int main() {
    char line[100];
    char ch;

    while ((ch = getchar()) != EOF) {
        printf("%c", ch);
    }

    return 0;
}