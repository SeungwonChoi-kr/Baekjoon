#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 21
#define TABLE_SIZE 131071

typedef struct Password {
    char web[MAX_LENGTH];
    char password[MAX_LENGTH];
    struct Password* next;
} Password;

Password* list[TABLE_SIZE] = {NULL};

unsigned hashFunction(const char* web);
void insertWeb(const char* web, const char* password);
void searchWeb(unsigned hash_value, const char* web);
int mapCharToInt(char c);

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        char* web = (char*)malloc(MAX_LENGTH);
        char* password = (char*)malloc(MAX_LENGTH);
        scanf("%s", web);
        scanf("%s", password);

        insertWeb(web, password);
    }

    for (int i = 0; i < M; i++) {
        char* web = (char*)malloc(MAX_LENGTH * sizeof(char));
        scanf("%s", web);

        searchWeb(hashFunction(web), web);
        free(web);
    }

    return 0;
}

unsigned hashFunction(const char* web) {
    unsigned hash_value = 0;
    int p = 31;

    while (*web) {
        hash_value = (hash_value * p + mapCharToInt(*web)) % TABLE_SIZE;
        web++;
    }

    return hash_value;
}

void insertWeb(const char* web, const char* password) {
    unsigned hash_value = hashFunction(web);

    Password* newPassword = (Password*)malloc(sizeof(Password));
    strcpy(newPassword->web, web);
    strcpy(newPassword->password, password);

    newPassword->next = list[hash_value];
    list[hash_value] = newPassword;
}

void searchWeb(unsigned hash_value, const char* web) {
    Password* password = list[hash_value];

    while (password) {
        if (strcmp(password->web, web) == 0) {
            printf("%s\n", password->password);
            break;
        } else {
            password = password->next;
        }
    }
}

int mapCharToInt(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 1;
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 27;
    else
        return 0;
}