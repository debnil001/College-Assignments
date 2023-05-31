#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Stack {
    int top;
    int arr[MAX];
};

void push(struct Stack* stack, int item) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

void evaluate(char* postfix) {
    struct Stack stack;
    stack.top = -1;
    for (int i = 0; i < strlen(postfix); i++) {
        char c = postfix[i];
        if (c >= '0' && c <= '9') {
            push(&stack, c - '0');
        }
        else {
            int op2 = pop(&stack);
            int op1 = pop(&stack);
            if (c == '+') {
                push(&stack, op1 + op2);
            }
            else if (c == '-') {
                push(&stack, op1 - op2);
            }
            else if (c == '/') {
                push(&stack, op1 / op2);
            }
            else {
                push(&stack, op1 * op2);
            }
        }
    }
    printf("%d\n", pop(&stack));
}

int main() {
    evaluate("231*+9-");
    return 0;
}