#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, length, cnt = 0, O_cnt = 0;
    bool isIOIing = false;
    char preChar;
    char* string;

    scanf("%d", &N);
    scanf("%d", &length);
    string = (char*)malloc((length + 1) * sizeof(char));
    scanf("%s", string);
    preChar = 'O'; // string[0]과 무조건 다른 문자가 될 것임

    for (int i = 0; i < length; i++) {
        if (string[i] != preChar) {
            preChar = string[i];

            if (string[i] == 'O') {
                O_cnt++;
            }
        } else {
            preChar = string[i];
            if (preChar == 'O') {
                O_cnt--;
            }

            if (O_cnt > 0) {
                if (O_cnt < N) {
                    O_cnt = 0;
                    continue;
                }

                cnt += O_cnt - N + 1;
            }

            O_cnt = 0;
        }

        if (i == length - 1) {
            if (preChar == 'O') {
                O_cnt--;
            }

            if (O_cnt > 0) {
                if (O_cnt < N) {
                    break;
                }

                cnt += O_cnt - N + 1;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}