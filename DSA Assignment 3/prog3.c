#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int stack[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, int value) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->stack[++stack->top] = value;
}

int pop(Stack* stack) {
    if (stack->top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->stack[stack->top--];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void printFileInReverse(FILE* file) {
    Stack stack;
    initializeStack(&stack);

    int num;
    while (fscanf(file, "%d", &num) == 1) {
        push(&stack, num);
    }

    printf("Data in reverse order:\n");
    while (!isEmpty(&stack)) {
        int value = pop(&stack);
        printf("%d ", value);
    }
    printf("\n");
}

int main() {
    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    printFileInReverse(file);

    fclose(file);
    return 0;
}
