#include<stdio.h>
#include <stdio.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
    // printf("%d pushed to stack\n", value);
}

char pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

char peek() {
    if (top < 0) {
        // printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

void printStack() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

int getPrecedence(char c){
    if(c=='+' || c=='-')
        return 1;
    if(c=='*'||c=='/')
        return 2;
    if(c=='^')
        return 3;
    return -1;
}
int compare(char c1, char c2){
    if(getPrecedence(c1)>=getPrecedence(c2))
        return 1;
    return -1;
}
void evaluateInfix(char infix[],int n){
    int i;
    char result[100];
    int index = 0;
    for(i=0;i<n;i++){
        if(infix[i]>='A' && infix[i]<='Z'){
            result[index++]=infix[i];
        }
        else if(infix[i]=='('){
            push(infix[i]);
        }
        else if(infix[i]==')'){
            while(!isEmpty() && peek()!='('){
                result[index++]=pop();
            }
            pop();
        }
        else{
            while(!isEmpty() && compare(peek(),infix[i])==1){
                result[index++]=pop();
            }
            push(infix[i]);
        }
    }
    while(!isEmpty()){
        result[index++]=pop();
    }

    for(int i=0;i<index;i++){
        printf("%c",result[i]);
    }
}
int main(){
    char infix[100]="A+B/C+D*(E-F)^G";
    evaluateInfix(infix,15);
    return 0;
}