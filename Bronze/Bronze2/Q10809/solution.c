#include <stdio.h>
#include <string.h>

int main() {
    char line[100];
    scanf("%s", line);

    int length = strlen(line);

    int alpha_array[26];
    for (int i = 0; i < 26; i++)
    {
        alpha_array[i] = -1;
    }

    int alpha_idx = 0;

    for (int i = 0; i < length; i++) {
        alpha_idx = line[i] - 'a';

        if (alpha_array[alpha_idx] == -1) {
            alpha_array[alpha_idx] = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%d ", alpha_array[i]);
    }

    return 0;
}