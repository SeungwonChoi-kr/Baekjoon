#include <stdio.h>
#include <string.h>

int main() {
    int length;
    scanf("%d", &length);

    char line[50];
    scanf("%s", line);

    unsigned long long int multiple = 1;
    unsigned long long int sum = 0;

    for (int i = 0; i < length; i++) {
        int alpha_num = line[i] - 'a' + 1;
        unsigned long long int tmp = multiple * alpha_num;

        sum += tmp;
        sum %= 1234567891;

        multiple *= 31;
        multiple %= 1234567891;
    }
    
    printf("%llu", sum);
    
    return 0;
}