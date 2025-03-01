#include <stdio.h>

int day_sum(int goal, int up) {
    int day = 0;

    if (goal % up == 0) {
        day = (goal / up);
    }
    else {
        day = (goal / up) + 1;
    }

    return day;
}

int main() {
    int up, down, goal;
    scanf("%d %d %d", &up, &down, &goal);

    if (up >= goal)
    {
        printf("1");
        return 0;
    }

    int cur_position = 0, day = 0;
    while (1)
    {
        day += day_sum(goal - cur_position, up);

        cur_position = up * day - down * (day - 1);
        if (cur_position >= goal)
        {
            printf("%d", day);
            break;
        }
        cur_position -= down;        
    }
    
    return 0;
}