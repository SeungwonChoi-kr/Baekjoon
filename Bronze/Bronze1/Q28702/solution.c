#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CheckFizzBuzz(int num) {
    if ((num % 3 == 0) && (num % 5 == 0)) {
        printf("FizzBuzz");
    }
    else if (num % 3 == 0) {
        printf("Fizz");
    }
    else if (num % 5 == 0) {
        printf("Buzz");
    }
    else {
        printf("%d", num);
    }    
}

int main() {
    char first[10];
    char second[10];
    char third[10];
    scanf("%s %s %s", first, second, third);

    int num = 0;

    if (strstr(first, "Fizz") == NULL && strstr(first, "Buzz") == NULL) {
        num = atoi(first);
        CheckFizzBuzz(num + 3);
    }
    else if (strstr(second, "Fizz") == NULL && strstr(second, "Buzz") == NULL) {
        num = atoi(second);
        CheckFizzBuzz(num + 2);
    }
    else if (strstr(third, "Fizz") == NULL && strstr(third, "Buzz") == NULL) {
        num = atoi(third);
        CheckFizzBuzz(num + 1);
    }
    
    return 0;
}