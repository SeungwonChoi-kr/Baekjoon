#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 131071

typedef struct Pocketmon {
    char name[21]; // 포켓몬 이름 최대 길이 20
    struct Pocketmon* next;
    int num;
} Pocketmon;

Pocketmon* pocketmon_book[TABLE_SIZE] = {NULL};

unsigned hashFunction(const char* name);
void insertPocketmon(const char* name, int num);
void searchPocketmon(unsigned hashValue, const char* name);
int mapCharToInt(char c);

int main() {
    int N, question;
    scanf("%d %d", &N, &question);

    char** pocketmons = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        char* pocketmon = (char*)malloc(21 * sizeof(char));
        scanf("%s", pocketmon);
        pocketmons[i] = pocketmon;
        insertPocketmon(pocketmon, i);
    }

    for (int i = 0; i < question; i++) {
        char answer[21];
        scanf("%s", answer);

        if (isalpha(answer[0])) {
            searchPocketmon(hashFunction(answer), answer);
        } else {
            printf("%s\n", pocketmons[atoi(answer) - 1]);
        }
    }

    return 0;
}

unsigned hashFunction(const char* name) {
    unsigned hash = 0;
    int p = 31;
    while (*name) {
        hash = (hash * p + (mapCharToInt(*name))) % TABLE_SIZE; // 문자가 앞에 있을수록 가중치를 더 곱해줌
        name++;
    }
    return hash;
}

void insertPocketmon(const char* name, int num) {
    unsigned hashValue = hashFunction(name);
    Pocketmon* newPocketmon = (Pocketmon*)malloc(sizeof(Pocketmon));
    strcpy(newPocketmon->name, name);
    newPocketmon->num = num;
    newPocketmon->next = pocketmon_book[hashValue];
    pocketmon_book[hashValue] = newPocketmon;
}

void searchPocketmon(unsigned hashValue, const char* name) {
    Pocketmon* pocketmon = pocketmon_book[hashValue];
    while (pocketmon->next) {
        if (strcmp(pocketmon->name, name) == 0) {
            break;
        } else {
            pocketmon = pocketmon->next;
        }
    }

    printf("%d\n", pocketmon->num + 1);
}

int mapCharToInt(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 1;
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 27;
    else
        return 0;
}