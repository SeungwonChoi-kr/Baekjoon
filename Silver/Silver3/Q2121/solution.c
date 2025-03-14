#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 131071
#define X_PRIME 73856093
#define Y_PRIME 19349663

typedef struct SimpleXY {
    int x;
    int y;
} SimpleXY;

typedef struct CRDNT {
    int x;
    int y;
    struct CRDNT* next;
} CRDNT;

CRDNT* table[TABLE_SIZE] = {NULL};

unsigned hashFunc(int x, int y);
void insertCRDNT(int x, int y);
bool searchCRDNT(int x, int y);
bool checkRectangle(int x, int y, int width, int height);

int main() {
    int N, width, height, x, y, rec_cnt = 0;
    scanf("%d", &N);
    scanf("%d %d", &width, &height);

    SimpleXY** coordinates = (SimpleXY**)malloc(N * sizeof(SimpleXY*));

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        insertCRDNT(x, y);

        SimpleXY* newXY = (SimpleXY*)malloc(sizeof(SimpleXY));
        newXY->x = x;
        newXY->y = y;
        coordinates[i] = newXY;
    }
    for (int i = 0; i < N; i++) {
        if (checkRectangle(coordinates[i]->x, coordinates[i]->y, width, height)) {
            rec_cnt++;
        }
    }
    printf("%d", rec_cnt);

    return 0;
}

unsigned hashFunc(int x, int y) {
    unsigned hash_x = x ^ (x >> 31) % TABLE_SIZE; // 음수일 경우 양수로 변환 (-3 -> 2, -7 -> 6)
    unsigned hash_y = y ^ (y >> 31) % TABLE_SIZE; // "

    hash_x = (hash_x * X_PRIME) % TABLE_SIZE;
    hash_y = (hash_y * Y_PRIME) % TABLE_SIZE;

    return (hash_x * hash_y) % TABLE_SIZE;
}

void insertCRDNT(int x, int y) {
    unsigned hash_value = hashFunc(x, y);

    CRDNT* newXY = (CRDNT*)malloc(sizeof(CRDNT));
    newXY->x = x;
    newXY->y = y;
    newXY->next = table[hash_value];

    table[hash_value] = newXY;
}

bool searchCRDNT(int x, int y) {
    unsigned hash_value = hashFunc(x, y);
    CRDNT* pivot = table[hash_value];
    while (pivot) {
        if (pivot->x == x && pivot->y == y) {
            return true;
        } else {
            pivot = pivot->next;
        }
    }
    return false;
}

bool checkRectangle(int x, int y, int width, int height) {
    bool status = false;

    if (searchCRDNT(x, y + height)) {
        if (searchCRDNT(x + width, y)) {
            if (searchCRDNT(x + width, y + height)) {
                status = true;
            }
        }
    }

    return status;
}
