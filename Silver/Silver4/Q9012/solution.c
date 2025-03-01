#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    char ps;
    struct Node* next;
} Node;

void checkString(char* line, int* result, int time);

int main() {
    int T;
    scanf("%d", &T);
    int* result = (int*)malloc(sizeof(int) * T);

    for (int t = 0; t < T; t++) {
        char line[51];
        scanf("%s", line);

        checkString(line, result, t);
    }

    for (int i = 0; i < T; i++)
    {
        if (result[i]) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}

void checkString(char* line, int* result, int time) {
    Node* top = NULL;
    int i = 0;
    int length = strlen(line);
    bool isVPS = false;

    if (length % 2 != 0) {
        isVPS = false;
    }
    else {
        for (i = 0; i < length; i++) {
            if (line[i] == '(') {
                Node* node = (Node*)malloc(sizeof(Node));
                node->ps = line[i];

                if (i == 0) {
                    top = node;
                }
                else {
                    node->next = top;
                    top = node;
                }
            }
            else if (line[i] == ')') {
                if (top != NULL) {
                    top = top->next;
                    isVPS = true;
                }
                else {
                    isVPS = false;
                    break;
                }
            }
        }
    }

    if (top != NULL) {
        isVPS = false;
    }
    

    if (isVPS) {
        result[time] = 1;
    }
    else {
        result[time] = 0;
    }
}