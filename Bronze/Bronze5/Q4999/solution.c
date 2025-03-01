#include <stdio.h>
#include <string.h>

int main() {
    char jaehwan[1000];
    char doctor[1000];

    scanf("%s", jaehwan);
    scanf("%s", doctor);

    if (strlen(jaehwan) >= strlen(doctor)) {
        printf("go");
    }
    else {
        printf("no");
    }

    return 0;
}