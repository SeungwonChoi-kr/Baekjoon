#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int loop = 0; loop < T; loop++) {
        int floor, room;
        scanf("%d %d", &floor, &room);
        
        int** floors = (int**)malloc(sizeof(int*) * (floor + 1));
        int** sub_floors = (int**)malloc(sizeof(int*) * (floor + 1));
        for (int i = 0; i <= floor; i++) {
            int* rooms = (int*)malloc(sizeof(int) * room);
            int* sub_rooms = (int*)malloc(sizeof(int) * room);
            floors[i] = rooms;
            sub_floors[i] = sub_rooms;
        }

        for (int i = 0; i < room; i++) {
            *(*floors + i) = i + 1;
            *(*sub_floors + i) = i + 1;
        }
        
        for (int i = 1; i <= floor; i++)
        {
            for (int j = 0; j < room; j++)
            {
                int num = 0;
                for (int k = 0; k <= j; k++) {
                    num += *(*(floors + i - 1) + k);
                }
                
                *(*(sub_floors + i) + j) = num;
            }
            floors = sub_floors;
        }
        printf("%d\n", *(*(floors + floor) + room - 1));
    }

    return 0;
}