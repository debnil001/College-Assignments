#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        struct Node* temp = queue->front;
        int data = temp->data;
        queue->front = queue->front->next;
        free(temp);
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
        return data;
    }
}

void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        struct Node* temp = queue->front;
        printf("Queue: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void reverseQueue(struct Queue* queue) {
    struct Node* stack = NULL;

    // Pop elements from the queue and push them onto the stack
    while (!isEmpty(queue)) {
        int data = dequeue(queue);
        struct Node* newNode = createNode(data);
        newNode->next = stack;
        stack = newNode;
    }

    // Pop elements from the stack and enqueue them back into the queue
    while (stack != NULL) {
        int data = stack->data;
        enqueue(queue, data);
        struct Node* temp = stack;
        stack = stack->next;
        free(temp);
    }
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("Original ");
    displayQueue(queue);

    reverseQueue(queue);

    printf("Reversed ");
    displayQueue(queue);

    return 0;
}
