#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMD_MAX 100001

typedef struct Node {
    short num;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct Doubly_List {
    Node* head;
    Node* tail;
} Doubly_List;

void insert_Node(Doubly_List* linked_list, short num);
void pop_Node(Doubly_List* linked_list, bool isRotated);
void executing_command(char* command, int num);
void show_List(Doubly_List* linked_list, bool isRotated);

int main() {
    int T;
    scanf("%d", &T);

    char* command;
    int num;
    for (int t = 0; t < T; t++) {
        command = (char*)calloc(CMD_MAX, sizeof(char));
        scanf("%s", command);
        scanf("%d", &num);
        executing_command(command, num);
        free(command);
    }

    return 0;
}

void insert_Node(Doubly_List* linked_list, short num) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->num = num;
    node->prev = NULL;
    node->next = NULL;

    if (linked_list->head == NULL) {
        linked_list->head = node;
        linked_list->tail = node;
    } else {
        linked_list->tail->next = node;
        node->prev = linked_list->tail;
        linked_list->tail = node;
    }
}

void pop_Node(Doubly_List* linked_list, bool isRotated) {
    if (linked_list->head == NULL) {
        return;
    } else if (linked_list->head->next == NULL) {
        Node* tmp = linked_list->head;
        linked_list->head = NULL;
        linked_list->tail = NULL;
        free(tmp);
        return;
    } else {
        if (!isRotated) {
            Node* tmp = linked_list->head;
            linked_list->head->next->prev = NULL;
            linked_list->head = linked_list->head->next;
            free(tmp);
        } else {
            Node* tmp = linked_list->tail;
            linked_list->tail->prev->next = NULL;
            linked_list->tail = linked_list->tail->prev;
            free(tmp);
        }
    }
}

void executing_command(char* command, int num) {
    Doubly_List* linked_list = (Doubly_List*)malloc(sizeof(Doubly_List));
    linked_list->head = NULL;
    linked_list->tail = NULL;

    int cmd_len = strlen(command);
    bool isRotated = false;
    bool isError = false;

    scanf(" [");
    for (int i = 0; i < num; i++) {
        short val;
        if (i == 0) {
            scanf(" %hd", &val);
        } else {
            scanf(" ,%hd", &val);
        }
        insert_Node(linked_list, val);
    }
    scanf(" ]");

    for (int i = 0; i < cmd_len; i++) {
        if (command[i] == 'D') {
            if (linked_list->head == NULL) {
                isError = true;
                break;
            }
            pop_Node(linked_list, isRotated);
        } else {
            isRotated = !isRotated;
        }
    }

    if (isError) {
        printf("error\n");
    } else {
        show_List(linked_list, isRotated);
    }

    Node* cur = linked_list->head;
    while (cur) {
        Node* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(linked_list);
}

void show_List(Doubly_List* linked_list, bool isRotated) {
    printf("[");

    if (!isRotated) { // 뒤집기가 안 됐을 때
        Node* node = linked_list->head;
        while (node) {
            printf("%hd", node->num);
            node = node->next;
            if (node != NULL) {
                printf(",");
            }
        }
    } else {
        Node* node = linked_list->tail;
        while (node) {
            printf("%hd", node->num);
            node = node->prev;
            if (node != NULL) {
                printf(",");
            }
        }
    }

    printf("]\n");
}
