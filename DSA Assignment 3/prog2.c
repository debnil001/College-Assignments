#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int *ptr;
    int top;
}Stack;

void initializeStack(Stack *stack){
    stack->top =-1;
    stack->ptr = (int*)malloc(10 * sizeof(int));
}
void display(Stack stack){
    if(stack.top==-1)
        printf("Stack is empty\n");
    else{
        int i;
        for(i=stack.top;i>=0;i--){
            printf("%d ",stack.ptr[i]);
        }
    }
}
void push(Stack *stack,int value) {
    if (stack->top >= 10) {
        printf("Stack overflow\n");
        return;
    }
    stack->ptr[++stack->top] = value;
    printf("%d pushed to stack\n", value);
}

int pop(Stack *stack) {
    if (stack->top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->ptr[stack->top--];
}

int peek(Stack *stack) {
    if (stack->top < 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->ptr[stack->top];
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}
int main(){
    Stack stack[10];
    int i;
    for( i=0; i<10; i++){
        initializeStack(&stack[i]);
    }
    push(&stack[0],10);
    push(&stack[0],10);
    push(&stack[1],20);
    push(&stack[1],30);
    push(&stack[7],55);

    for( i=0; i<10; i++){
        display(stack[i]);
    }
    return 0;
}