#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Deque {
    Node* head;
    Node* tail;
    int size;
} Deque;

Deque* create_deque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->head = NULL;
    deque->tail = NULL;
    deque->size = 0;
    return deque;
}

int is_empty(Deque* deque) {
    return deque->size == 0;
}

void add_first(Deque* deque, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = deque->head;
    node->prev = NULL;
    if (deque->head != NULL) {
        deque->head->prev = node;
    } else {
        deque->tail = node;
    }
    deque->head = node;
    deque->size++;
}

void add_last(Deque* deque, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    node->prev = deque->tail;
    if (deque->tail != NULL) {
        deque->tail->next = node;
    } else {
        deque->head = node;
    }
    deque->tail = node;
    deque->size++;
}

int remove_first(Deque* deque) {
    if (is_empty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }
    int value = deque->head->value;
    Node* temp = deque->head;
    deque->head = deque->head->next;
    if (deque->head != NULL) {
        deque->head->prev = NULL;
    } else {
        deque->tail = NULL;
    }
    free(temp);
    deque->size--;
    return value;
}

int remove_last(Deque* deque) {
    if (is_empty(deque)) {
        printf("Deque is empty.\n");
        return -1;
    }
    int value = deque->tail->value;
    Node* temp = deque->tail;
    deque->tail = deque->tail->prev;
    if (deque->tail != NULL) {
        deque->tail->next = NULL;
    } else {
        deque->head = NULL;
    }
    free(temp);
    deque->size--;
    return value;
}

void print_deque(Deque* deque) {
    if (is_empty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    Node* curr = deque->head;
    printf("Deque: ");
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Deque* deque = create_deque();
    add_first(deque, 1);
    add_last(deque, 2);
    add_first(deque, 3);
    add_last(deque, 4);
    print_deque(deque);
    remove_first(deque);
    remove_last(deque);
    print_deque(deque);
    return 0;
}
