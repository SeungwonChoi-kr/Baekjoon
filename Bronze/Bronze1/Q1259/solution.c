#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* next;
    char data;
} Node;


int main() {
    Node* top;
    int isPass = 0;

    char line[10];
    scanf("%s", line);

    while (strcmp(line, "0") != 0) {
        top = NULL;
        for (int i = 0; i < strlen(line); i++) {
            Node* node = (Node*)malloc(sizeof(Node));
            node->data = line[i];

            if (top == NULL) {
                top = node;
            }
            else {
                node->next = top;
                top = node;
            }
        }
        
        isPass = 1;
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] != top->data) {
                isPass = 0;
                break;
            }
            top = top->next;
        }

        if (isPass == 1) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
        scanf("%s", line);
    }

    return 0;
}