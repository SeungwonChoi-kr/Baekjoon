#include <stdio.h>
#include <string.h>

int main() {
    char score[10];
    scanf("%s", score);

    if (strcmp(score, "A+") == 0)
        printf("4.3");
    else if (strcmp(score, "A0") == 0)
        printf("4.0");
    else if (strcmp(score, "A-") == 0)
        printf("3.7");
    else if (strcmp(score, "B+") == 0)
        printf("3.3");
    else if (strcmp(score, "B0") == 0)
        printf("3.0");
    else if (strcmp(score, "B-") == 0)
        printf("2.7");
    else if (strcmp(score, "C+") == 0)
        printf("2.3");
    else if (strcmp(score, "C0") == 0)
        printf("2.0");
    else if (strcmp(score, "C-") == 0)
        printf("1.7");
    else if (strcmp(score, "D+") == 0)
        printf("1.3");
    else if (strcmp(score, "D0") == 0)
        printf("1.0");
    else if (strcmp(score, "D-") == 0)
        printf("0.7");
    else
        printf("0.0");
    
    return 0;
}