#include <ctype.h>
#include <stdio.h>

int main() {
    char str[1000000];
    scanf("%s", str);
    int index = 0;

    while (str[index]) {
        printf("%c", toupper(str[index++]));
    }

    return 0;
}