#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Member
{
    int age;
    char name[101];
} Member;

void sorting(Member* members, int N);

int main() {
    int N;
    int Age;
    char Name[101];

    scanf("%d", &N);
    Member* members = (Member*)malloc(sizeof(Member) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d %s", &Age, Name);

        members[i].age = Age;
        strcpy(members[i].name, Name);
    }

    sorting(members, N);

    for (int i = 0; i < N; i++) {
        printf("%d %s\n", members[i].age, members[i].name);
    }
    

    return 0;
}

void sorting(Member* members, int N) {
    int index = 0;
    int min_age;
    int dup_member;
    int prev_min_age = 0;
    Member* copy_members = (Member*)malloc(sizeof(Member) * N);
    
    while (index < N) {
        if (index != 0)
            prev_min_age = min_age;

        min_age = 201;

        for (int i = 0; i < N; i++) {
            if (members[i].age < min_age && members[i].age > prev_min_age) {
                min_age = members[i].age;
                dup_member = 1;
            }
            else if (members[i].age == min_age && members[i].age > prev_min_age) {
                dup_member++;
            }
        }

        for (int i = 0; i < N; i++) {
            if (members[i].age == min_age) {
                copy_members[index].age = min_age;
                strcpy(copy_members[index++].name, members[i].name);

                dup_member--;
            }

            if (dup_member == 0) {
                break;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        members[i] = copy_members[i];
    }
}