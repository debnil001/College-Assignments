#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int priority;
    struct node* next;
} Node;

Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node** head, int data, int priority) {
    Node* newNode = createNode(data, priority);
    
    if (*head==NULL || priority<(*head)->priority) {
        newNode->next=*head;
        *head=newNode;
    } else {
        Node* current=*head;
        while (current->next != NULL && current->next->priority <= priority) {
            current=current->next;
        }
        newNode->next=current->next;
        current->next=newNode;
    }
}

void dequeue(Node** head) {
    if (*head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    
    Node* temp=*head;
    *head=(*head)->next;
    free(temp);
}

int front(Node* head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return head->data;
}

int main() {
    Node* head = NULL;

    enqueue(&head, 10, 2);
    enqueue(&head, 20, 1);
    enqueue(&head, 30, 3);

    printf("Front element: %d\n", front(head));
    dequeue(&head);
    printf("Front element: %d\n", front(head));
    dequeue(&head);
    printf("Front element: %d\n", front(head));
    dequeue(&head);

    dequeue(&head);

    return 0;
}
