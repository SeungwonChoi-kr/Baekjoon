#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 131071

typedef struct Person {
    char name[21];
    struct Person* next;
    bool noListenSee;
} Person;

Person* person_table[TABLE_SIZE] = {NULL};

unsigned hashFunction(const char* name);
void insertPerson(const char* name);
bool searchPerson(unsigned hash_value, const char* name);
int mapCharToInt(char c);

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    if (N < M) {
        int tmp = N;
        N = M;
        M = tmp;
    }

    Person** list = (Person**)calloc(N, sizeof(Person*));
    int n = 0;

    for (int i = 0; i < N; i++) {
        char name[21];
        scanf("%s", name);
        insertPerson(name);
    }

    for (int i = 0; i < M; i++) {
        char name[21];
        scanf("%s", name);

        if (searchPerson(hashFunction(name), name)) {
            Person* person = (Person*)malloc(sizeof(Person));
            strcpy(person->name, name);
            list[n++] = person;
        }
    }

    char tmp[21];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(list[i]->name, list[j]->name) > 0) {
                strcpy(tmp, list[i]->name);
                strcpy(list[i]->name, list[j]->name);
                strcpy(list[j]->name, tmp);
            }
        }
    }

    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        printf("%s\n", list[i]->name);
    }

    return 0;
}

unsigned hashFunction(const char* name) {
    unsigned hash_value = 0;

    while (*name) {
        hash_value = (31 * hash_value + mapCharToInt(*name)) % TABLE_SIZE;
        name++;
    }

    return hash_value;
}

void insertPerson(const char* name) {
    unsigned hash_value = hashFunction(name);
    Person* person = (Person*)malloc(sizeof(Person));
    strcpy(person->name, name);
    person->next = person_table[hash_value];
    person_table[hash_value] = person;
}

bool searchPerson(unsigned hash_value, const char* name) {
    Person* person = person_table[hash_value];

    if (person) {
        while (person) {
            if (strcmp(person->name, name) == 0) {
                return true;
            } else {
                person = person->next;
            }
        }
        return false;
    } else
        return false;
}

int mapCharToInt(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 1;
    else if (c >= 'a' && c <= 'z')
        return c - 'a' + 27;
    else
        return 0;
}