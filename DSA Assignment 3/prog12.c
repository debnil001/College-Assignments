#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100  // Maximum size of the queues

struct Queue {
    int elements[MAX_SIZE];
    int front;
    int rear;
};

void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

bool isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(struct Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->elements[queue->rear] = data;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        initialize(queue);
    } else {
        queue->front++;
    }
    return data;
}

bool isEqual(struct Queue* q1, struct Queue* q2) {
    if (q1->front == -1 && q2->front == -1) {
        return true;
    }
    if ((q1->rear - q1->front) != (q2->rear - q2->front)) {
        return false;
    }
    int i, j;
    for (i = q1->front, j = q2->front; i <= q1->rear && j <= q2->rear; i++, j++) {
        if (q1->elements[i] != q2->elements[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    struct Queue q1, q2;
    initialize(&q1);
    initialize(&q2);

    enqueue(&q1, 10);
    enqueue(&q1, 20);
    enqueue(&q1, 30);

    enqueue(&q2, 10);
    enqueue(&q2, 20);
    enqueue(&q2, 30);

    bool result = isEqual(&q1, &q2);
    if (result) {
        printf("Queues are equal.\n");
    } else {
        printf("Queues are not equal.\n");
    }

    dequeue(&q2);

    result = isEqual(&q1, &q2);
    if (result) {
        printf("Queues are equal.\n");
    } else {
        printf("Queues are not equal.\n");
    }

    return 0;
}
