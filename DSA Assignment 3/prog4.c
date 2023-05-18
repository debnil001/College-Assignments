#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int stack[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = -1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->stack[++stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->stack[stack->top--];
}

bool isStackEqual(Stack* stack1, Stack* stack2) {
    if (stack1->top != stack2->top) {
        return false;
    }

    for (int i = 0; i <= stack1->top; i++) {
        if (stack1->stack[i] != stack2->stack[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    Stack stack1, stack2;
    initializeStack(&stack1);
    initializeStack(&stack2);

    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);

    push(&stack2, 10);
    push(&stack2, 20);
    push(&stack2, 30);

    bool isEqual = isStackEqual(&stack1, &stack2);

    if (isEqual) {
        printf("The stacks are equal.\n");
    } else {
        printf("The stacks are not equal.\n");
    }

    return 0;
}
