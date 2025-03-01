#include <stdio.h>
#include <string.h>

int main() {
    char line[1000000];
    gets(line);

    int count = 0;
    char* tmp = strtok(line, " ");

    while (tmp != NULL) {
        count++;
        tmp = strtok(NULL, " ");
    }

    printf("%d", count);

    return 0;
}