#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to perform Bubble Sort by interchanging links
void bubbleSort(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    int swapped;
    struct Node *prev, *current, *next, *end = NULL;

    do {
        swapped = 0;
        prev = NULL;
        current = head;

        while (current->next != end) {
            next = current->next;

            if (current->data > next->data) {
                // Interchange the links between current and next nodes
                if (prev == NULL) {
                    head = next;
                } else {
                    prev->next = next;
                }
                current->next = next->next;
                next->next = current;

                prev = next;
                swapped = 1;
            } else {
                prev = current;
                current = next;
            }
        }
        end = current; // Mark the last sorted element
    } while (swapped);
}

// Function to free the memory occupied by the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = newNode(10);
    head->next = newNode(7);
    head->next->next = newNode(5);
    head->next->next->next = newNode(8);
    head->next->next->next->next = newNode(3);

    printf("Linked List before sorting: ");
    printList(head);

    bubbleSort(head);

    printf("Linked List after sorting: ");
    printList(head);

    // Free the memory occupied by the linked list
    freeList(head);

    return 0;
}
