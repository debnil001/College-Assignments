#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct PriorityQueue {
    int elements[MAX_SIZE];
    int priorities[MAX_SIZE];
    int size;
};

void initialize(struct PriorityQueue* pq) {
    pq->size = 0;
}

int isEmpty(struct PriorityQueue* pq) {
    return (pq->size == 0);
}

int isFull(struct PriorityQueue* pq) {
    return (pq->size == MAX_SIZE);
}

void enqueue(struct PriorityQueue* pq, int element, int priority) {
    if (isFull(pq)) {
        printf("Priority queue is full.\n");
        return;
    }

    int index = pq->size - 1;
    while (index >= 0 && pq->priorities[index] < priority) {
        pq->elements[index + 1] = pq->elements[index];
        pq->priorities[index + 1] = pq->priorities[index];
        index--;
    }

    pq->elements[index + 1] = element;
    pq->priorities[index + 1] = priority;
    pq->size++;
}

int dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty.\n");
        return -1;
    }

    int element = pq->elements[0];
    int priority = pq->priorities[0];

    for (int i = 1; i < pq->size; i++) {
        pq->elements[i - 1] = pq->elements[i];
        pq->priorities[i - 1] = pq->priorities[i];
    }

    pq->size--;

    return element;
}

void display(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty.\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Element: %d, Priority: %d\n", pq->elements[i], pq->priorities[i]);
    }
}

int main() {
    struct PriorityQueue pq;
    initialize(&pq);

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);
    enqueue(&pq, 40, 2);

    display(&pq);

    int element = dequeue(&pq);
    printf("Dequeued Element: %d\n", element);

    display(&pq);

    return 0;
}
