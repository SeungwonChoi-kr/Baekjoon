#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    int* data;
} Stack;

void init_stack(Stack* s, int N);
void push(Stack* s, int data);
int pop(Stack* s);
int is_empty(Stack* s);

int main() {
    int N;
    scanf("%d", &N);

    Stack* stack = (Stack*)malloc(sizeof(Stack));
    init_stack(stack, N);

    int* results = (int*)malloc(2 * N * sizeof(int)); // 0은 pop, 1은 push
    for (int i = 0; i < 2 * N; i++) {
        results[i] = 2;
    }
    int idx = 0;

    int loop = 0;
    int is_passed = 0;
    int input_num;
    int stack_num = 1; // 스택에 넣을 숫자로 1부터 시작

    while (loop < N) {
        if (!is_passed) {
            scanf("%d", &input_num);
            loop++;
            is_passed = 1;
        }

        if (stack_num == input_num) {
            push(stack, stack_num++); // 넣다
            results[idx++] = 1;
            pop(stack);
            results[idx++] = 0; // 빼기

            is_passed = 0; // 새로운 입력을 받아야 함
        } else {
            if (stack_num > input_num) {
                if (pop(stack) == input_num) {
                    results[idx++] = 0;
                    is_passed = 0; // 새로운 입력을 받아야 함
                } else {
                    results[0] = -1;

                    for (int i = 1; i < 2 * N; i++)
                        results[i] = 2;

                    break;
                }
            } else {
                push(stack, stack_num++);
                results[idx++] = 1;
            }
        }
    }

    if (results[0] == -1)
        printf("NO");
    else {
        for (int i = 0; i < 2 * N; i++) {
            if (results[i] == 1)
                printf("+\n");
            else if (results[i] == 0)
                printf("-\n");
            else if (results[i] == 2)
                break;
        }
    }

    return 0;
}

void init_stack(Stack* s, int N) {
    s->top = -1;
    s->data = (int*)malloc(N * sizeof(int));
}

void push(Stack* s, int data) {
    s->data[++(s->top)] = data;
}

int pop(Stack* s) {
    if (is_empty(s))
        return -1;
    else
        return s->data[(s->top)--];
}

int is_empty(Stack* s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}