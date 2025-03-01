#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    char bracket;
    struct Node* prev;
} Node;


bool bracket(char* lines);

int main() {
    while (1) {
        char lines[101] = {'\0'};
        scanf("%[^.]%*c", lines);

        if (strlen(lines) == 0) {
            break;
        }
        else {
            if (bracket(lines)) {
                printf("yes\n");
            }
            else {
                printf("no\n");
            }
        }

        getchar();
    }

    return 0;
}

bool bracket(char* lines) {
    bool isMatched = true;
    int loop = strlen(lines);

    Node* top = NULL;

    for (int i = 0; i < loop; i++) {
        if (lines[i] == '[') {
            Node* node = (Node*)malloc(sizeof(Node));
            node->bracket = lines[i];

            if (top) {
                node->prev = top;
            }
            top = node;
        }
        else if (lines[i] == '(') {
            Node* node = (Node*)malloc(sizeof(Node));
            node->bracket = lines[i];

            if (top) {
                node->prev = top;
            }
            top = node;
        }
        else if (lines[i] == ')') {
            if (top == NULL) {
                isMatched = false;
                break;
            }
            else {
                if (top->bracket == '(') {
                    isMatched = true;
                    top = top->prev;
                }
                else {
                    isMatched = false;
                    break;
                }
            }
        }
        else if (lines[i] == ']') {
            if (top == NULL) {
                isMatched = false;
                break;
            }
            else {
                if (top->bracket == '[') {
                    isMatched = true;
                    top = top->prev;
                }
                else {
                    isMatched = false;
                    break;
                }
            }
        }
    }

    if (top) {
        isMatched = false;
    }

    return isMatched;
}