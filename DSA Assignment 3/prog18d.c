#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Priority Queue structure
struct PriorityQueue {
    struct Node** queues; // Array of linked lists
    int numPriorities;    // Number of priority levels
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to create a priority queue
struct PriorityQueue* createPriorityQueue(int numPriorities) {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    if (pq == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    pq->queues = (struct Node**)malloc(numPriorities * sizeof(struct Node*));
    if (pq->queues == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    pq->numPriorities = numPriorities;
    // Initialize each queue to NULL
    for (int i = 0; i < numPriorities; i++) {
        pq->queues[i] = NULL;
    }
    return pq;
}

// Function to check if the priority queue is empty
int isEmpty(struct PriorityQueue* pq) {
    for (int i = 0; i < pq->numPriorities; i++) {
        if (pq->queues[i] != NULL)
            return 0;
    }
    return 1;
}

// Function to enqueue an element with a given priority
void enqueue(struct PriorityQueue* pq, int data, int priority) {
    if (priority < 0 || priority >= pq->numPriorities) {
        printf("Invalid priority level!\n");
        return;
    }
    struct Node* newNode = createNode(data, priority);
    if (pq->queues[priority] == NULL) {
        pq->queues[priority] = newNode;
    } else {
        struct Node* current = pq->queues[priority];
        struct Node* prev = NULL;
        while (current != NULL && current->priority <= priority) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) {
            newNode->next = pq->queues[priority];
            pq->queues[priority] = newNode;
        } else {
            newNode->next = prev->next;
            prev->next = newNode;
        }
    }
}

// Function to dequeue and return the highest priority element
int dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty!\n");
        exit(1);
    }
    struct Node* highestPriorityQueue = NULL;
    for (int i = 0; i < pq->numPriorities; i++) {
        if (pq->queues[i] != NULL) {
            highestPriorityQueue = pq->queues[i];
            pq->queues[i] = pq->queues[i]->next;
            break;
        }
    }
    int data = highestPriorityQueue->data;
    free(highestPriorityQueue);
    return data;
}

// Function to print the priority queue
void printPriorityQueue(struct PriorityQueue* pq) {
    printf("Priority Queue:\n");
    for (int i = 0; i < pq->numPriorities; i++) {
        printf("Priority %d: ", i);
        struct Node* current = pq->queues[i];
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
    printf("\n");
}

// Function to free the memory occupied by the priority queue
void freePriorityQueue(struct PriorityQueue* pq) {
    for (int i = 0; i < pq->numPriorities; i++) {
        struct Node* current = pq->queues[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(pq->queues);
    free(pq);
}

int main() {
    int numPriorities;
    printf("Enter the number of priority levels: ");
    scanf("%d", &numPriorities);

    struct PriorityQueue* pq = createPriorityQueue(numPriorities);

    int choice;
    do {
        printf("Priority Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Priority Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int data, priority;
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                printf("Enter the priority level (0-%d): ", numPriorities - 1);
                scanf("%d", &priority);
                enqueue(pq, data, priority);
                break;
            }
            case 2: {
                if (!isEmpty(pq)) {
                    int data = dequeue(pq);
                    printf("Dequeued element: %d\n", data);
                } else {
                    printf("Priority Queue is empty!\n");
                }
                break;
            }
            case 3:
                printPriorityQueue(pq);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    // Free the memory occupied by the priority queue
    freePriorityQueue(pq);

    return 0;
}
