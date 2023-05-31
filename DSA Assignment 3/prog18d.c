#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Structure for Priority Queue
struct PriorityQueue {
    struct Node* front;
    struct Node* rear;
};

void initializeQueue(struct PriorityQueue* pq) {
    pq->front = NULL;
    pq->rear = NULL;
}

int isEmpty(struct PriorityQueue* pq) {
    return pq->front == NULL;
}

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(struct PriorityQueue* pq, int element, int priority) {
    struct Node* newNode = createNode(element, priority);
    
    // If the priority queue is empty or the new node has higher priority than the front node
    if (isEmpty(pq) || priority > pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        struct Node* temp = pq->front;
        
        // Traverse the linked list to find the appropriate position to insert the new node
        while (temp->next != NULL && temp->next->priority >= priority) {
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    // If the new node is the only node or has higher priority than the rear node
    if (isEmpty(pq) || priority > pq->rear->priority) {
        pq->rear = newNode;
    }
}

int dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty. Cannot dequeue element.\n");
        return -1;
    }
    
    struct Node* temp = pq->front;
    int element = temp->data;
    pq->front = pq->front->next;
    
    if (pq->front == NULL) {
        pq->rear = NULL;
    }
    
    free(temp);
    return element;
}

int getHighestPriority(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return -1;
    }
    
    return pq->front->data;
}

void displayQueue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty.\n");
        return;
    }
    
    struct Node* temp = pq->front;
    
    printf("Priority Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
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
    int highestPriority = getHighestPriority(&pq);
    printf("Highest Priority: %d\n", highestPriority);
    int dequeuedElement = dequeue(&pq);
    printf("Dequeued Element: %d\n", dequeuedElement); 
    displayQueue(&pq); 
    
    return 0;
}