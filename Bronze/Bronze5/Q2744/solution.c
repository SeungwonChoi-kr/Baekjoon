#include <stdio.h>
#include <string.h>

int main() {
    char line[100];
    scanf("%s", line);

    for (int i = 0; i < strlen(line); i++)
    {
        if (line[i] >= 'a' && line[i] <= 'z') {
            line[i] = line[i] + 'A' - 'a';
        }
        else if (line[i] >= 'A' && line[i] <= 'Z') {
            line[i] = line[i] + 'a' - 'A';
        }
    }
    
    printf("%s", line);

    return 0;
}