#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int value) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }

    StackNode* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}

void createStacks(Stack** stacks, int n) {
    for (int i = 0; i < n; i++) {
        stacks[i] = (Stack*)malloc(sizeof(Stack));
        if (stacks[i] == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        initializeStack(stacks[i]);
    }
}

void pushToStack(Stack** stacks, int n, int stackIndex, int value) {
    if (stackIndex < 0 || stackIndex >= n) {
        printf("Invalid stack index.\n");
        return;
    }
    push(stacks[stackIndex], value);
    printf("%d pushed to Stack %d\n", value, stackIndex + 1);
}

int popFromStack(Stack** stacks, int n, int stackIndex) {
    if (stackIndex < 0 || stackIndex >= n) {
        printf("Invalid stack index.\n");
        return -1;
    }
    return pop(stacks[stackIndex]);
}

void freeStack(Stack* stack) {
    StackNode* current = stack->top;
    while (current != NULL) {
        StackNode* temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;
}

void destroyStacks(Stack** stacks, int n) {
    for (int i = 0; i < n; i++) {
        freeStack(stacks[i]);
        free(stacks[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of stacks: ");
    scanf("%d", &n);

    Stack** stacks = (Stack**)malloc(n * sizeof(Stack*));
    if (stacks == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    createStacks(stacks, n);

    pushToStack(stacks, n, 0, 10);
    pushToStack(stacks, n, 0, 20);
    pushToStack(stacks, n, 1, 30);
    pushToStack(stacks, n, 2, 40);

    printf("Popped from Stack 0: %d\n", popFromStack(stacks, n, 0));
    printf("Popped from Stack 1: %d\n", popFromStack(stacks, n, 1));
    printf("Popped from Stack 2: %d\n", popFromStack(stacks, n, 2));

    destroyStacks(stacks, n);
    free(stacks);

    return 0;
}
