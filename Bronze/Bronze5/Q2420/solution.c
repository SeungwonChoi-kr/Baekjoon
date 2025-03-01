#include <stdio.h>

int main() 
{
    long long int a = 0, b = 0;

    scanf("%lld %lld", &a, &b);

    if (a - b < 0) {
        printf("%lld", -(a - b));
    }
    else {
        printf("%lld", a - b);
    }
    return 0;
}