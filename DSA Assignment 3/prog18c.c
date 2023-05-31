#include <stdio.h>

#define MAX_SIZE 100

struct PriorityQueue {
    int data[MAX_SIZE][2];
    int size;
};

void initializeQueue(struct PriorityQueue* pq) {
    pq->size = 0;
}

int isEmpty(struct PriorityQueue* pq) {
    return pq->size == 0;
}
int isFull(struct PriorityQueue* pq) {
    return pq->size == MAX_SIZE;
}

void enqueue(struct PriorityQueue* pq, int element, int priority) {
    if (isFull(pq)) {
        printf("Priority Queue is full. Cannot enqueue element.\n");
        return;
    }
    
    int i;
    for (i = pq->size - 1; i >= 0; i--) {
        if (priority > pq->data[i][1]) {
            pq->data[i + 1][0] = pq->data[i][0];
            pq->data[i + 1][1] = pq->data[i][1];
        } else {
            break;
        }
    }
    
    pq->data[i + 1][0] = element;
    pq->data[i + 1][1] = priority;
    pq->size++;
}

int dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty. Cannot dequeue element.\n");
        return -1;
    }
    
    int element = pq->data[pq->size - 1][0];
    pq->size--;
    
    return element;
}

int front(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return -1;
    }
    
    return pq->data[pq->size - 1][0];
}

void displayQueue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return;
    }
    
    printf("Priority Queue: ");
    for (int i = pq->size - 1; i >= 0; i--) {
        printf("%d ", pq->data[i][0]);
    }
    printf("\n");
}

int main() {
    struct PriorityQueue pq;
    
    initializeQueue(&pq);
    
    enqueue(&pq, 10, 3);
    enqueue(&pq, 20, 2);
    enqueue(&pq, 30, 1);
    enqueue(&pq, 40, 4);
    
    displayQueue(&pq); 
    int highestPriority = front(&pq);
    printf("Highest Priority: %d\n", highestPriority); 
    
    int dequeuedElement = dequeue(&pq);
    printf("Dequeued Element: %d\n", dequeuedElement); // Output: Dequeued Element: 40
    
    displayQueue(&pq); // Output: Priority Queue: 10 20 30
    
    return 0;
}
