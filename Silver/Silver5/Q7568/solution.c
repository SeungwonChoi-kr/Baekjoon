#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Person {
    int weight;
    int height;
    int real_rank;
} Person;

void ranking(Person* people, int N);

int main() {
    int N;
    scanf("%d", &N);

    Person* people = (Person*)malloc(sizeof(Person) * N);

    for (int i = 0; i < N; i++) {
        int weight, height;
        scanf("%d %d", &weight, &height);

        people[i].weight = weight;
        people[i].height = height;
        people[i].real_rank = 0;
    }

    ranking(people, N);

    for (int i = 0; i < N; i++) {
        printf("%d ", people[i].real_rank);
    }

    return 0;
}

void ranking(Person* people, int N) {
    int rank;

    for (int i = 0; i < N; i++) {
        rank = 0;

        for (int j = 0; j < N; j++) {
            if (people[i].weight < people[j].weight && people[i].height < people[j].height) {
                rank++;
            }
        }
        people[i].real_rank = rank + 1;
    }
}