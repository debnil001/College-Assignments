#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char arr[MAX_SIZE];
    int top;
};

void push(struct Stack *st, char c) {
    if (st->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    st->top++;
    st->arr[st->top] = c;
}

char pop(struct Stack *st) {
    if (st->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    char c = st->arr[st->top];
    st->top--;
    return c;
}

bool isEmpty(struct Stack *st) {
    return st->top == -1;
}

char peek(struct Stack *st) {
    if (st->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return st->arr[st->top];
}

bool checkBalanceParanthesis(char *s) {
    struct Stack st;
    st.top = -1;
    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];
        if (c == ')') {
            while (!isEmpty(&st) && peek(&st) != '(') {
                pop(&st);
            }
            if (isEmpty(&st)) {
                return false;
            } else {
                pop(&st);
            }
        } else if (c == '}') {
            while (!isEmpty(&st) && peek(&st) != '{') {
                pop(&st);
            }
            if (isEmpty(&st)) {
                return false;
            } else {
                pop(&st);
            }
        } else if (c == ']') {
            while (!isEmpty(&st) && peek(&st) != '[') {
                pop(&st);
            }
            if (isEmpty(&st)) {
                return false;
            } else {
                pop(&st);
            }
        } else {
            push(&st, c);
        }
    }
    return isEmpty(&st);
}

int main() {
    printf("%d\n", checkBalanceParanthesis("[(5+6/{4/1}*4+8-8+(1-3))]}"));
    return 0;
}
