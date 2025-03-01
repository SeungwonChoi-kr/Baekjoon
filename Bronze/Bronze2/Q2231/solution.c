#include <stdio.h>

int main() {
    int cal = 1000000;
    int length = 7;

    int input;
    scanf("%d", &input);

    while (input / cal == 0) {
        cal /= 10;
        length--;
    }

    int array[7] = {0};
    int x = input - 9 * length;
    while (1) {
        int tmp_cal = cal;
        int array_sum = 0;

        for (int i = 0; i < length; i++) {
            array[length - i - 1] = (x / tmp_cal) % 10;
            tmp_cal /= 10;
        }

        for (int i = 0; i < 7; i++) {
            array_sum += array[i];
        }
        
        if (x + array_sum != input) {
            if (x < input) {
                x++;
            }
            else {
                printf("0");
                break;
            }
        }
        else {
            printf("%d", x);
            break;
        }
    }
    
    return 0;
}