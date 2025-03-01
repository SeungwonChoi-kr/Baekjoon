#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int H, W, N;
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d", &H, &W, &N);
        int floor = N % H;

        int room = N / H + 1;
        if (floor == 0) {
            floor = H;
            room--;
        }

        if (room < 10) {
            printf("%d0%d\n", floor, room);
        }
        else {
            printf("%d%d\n", floor, room);
        }
    }
    
    return 0;
}