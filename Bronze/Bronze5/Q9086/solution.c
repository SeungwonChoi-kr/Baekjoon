#include <stdio.h>
#include <string.h>

int main() {
    int loop = 0;
    scanf("%d", &loop);

    char line[1000];

    for (int i = 0; i < loop; i++)
    {
        scanf("%s", line);

        printf("%c%c\n", line[0], line[strlen(line) - 1]);
    }
    
    return 0;
}