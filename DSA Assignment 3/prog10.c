#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUES 10  // Maximum number of queues

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue createQueue() {
    struct Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        if (queue->front == NULL) {
            queue->rear = NULL;
        }
    }
}

void displayQueue(struct Queue* queue) {
    if (queue->front == NULL) {
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

int main() {
    struct Queue queues[MAX_QUEUES];
    for (int i = 0; i < MAX_QUEUES; i++) {
        queues[i] = createQueue();
    }

    enqueue(&queues[0], 10);
    enqueue(&queues[1], 20);
    enqueue(&queues[0], 30);
    enqueue(&queues[2], 40);
    for (int i = 0; i < MAX_QUEUES; i++) {
        printf("Queue %d: ", i);
        displayQueue(&queues[i]);
    }

    dequeue(&queues[0]);
    dequeue(&queues[1]);
    dequeue(&queues[2]);

    for (int i = 0; i < MAX_QUEUES; i++) {
        printf("Queue %d: ", i);
        displayQueue(&queues[i]);
    }

    return 0;
}
