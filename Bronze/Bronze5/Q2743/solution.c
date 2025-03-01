#include <stdio.h>
#include <string.h>

int main() {
    char line[100];
    scanf("%s", line);
    
    printf("%lu", strlen(line));

    return 0;
}