#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int string_length = 0;
    char* tmp_string = (char*)malloc(sizeof(char) * 1000000);
    scanf("%s", tmp_string);
    string_length = strlen(tmp_string);

    char* string = (char*)malloc(sizeof(char) * (string_length + 1));
    strcpy(string, tmp_string);
    free(tmp_string);

    int alphabet[26] = {0};

    char tmp_ch = '\0';
    for (int i = 0; i < string_length; i++) {
        string[i] = tolower(string[i]);

        alphabet[string[i] - 97]++;
    }

    int dup = 1;
    int max = -1;

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] > max) {
            max = alphabet[i];
            dup = 1;
            tmp_ch = i + 97;
        }
        else if (alphabet[i] == max) {
            dup++;
        }
    }

    if (dup > 1) {
        printf("?");
    }
    else {
        printf("%c", toupper(tmp_ch));
    }

    return 0;
}