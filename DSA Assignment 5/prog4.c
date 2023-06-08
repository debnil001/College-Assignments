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

// Function to swap two nodes by interchanging links
void swapNodes(struct Node** head, struct Node* prevA, struct Node* prevB) {
    struct Node* nodeA = prevA->next;
    struct Node* nodeB = prevB->next;

    // Swap the next pointers of prevA and prevB
    prevA->next = nodeB;
    prevB->next = nodeA;

    // Swap the next pointers of nodeA and nodeB
    struct Node* temp = nodeB->next;
    nodeB->next = nodeA->next;
    nodeA->next = temp;

    // Update the head pointer if the first node is involved in swapping
    if (*head == nodeA)
        *head = nodeB;
    else if (*head == nodeB)
        *head = nodeA;
}

// Bubble sort by interchanging links
void bubbleSort(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    int swapped;
    struct Node* current;
    struct Node* last = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                swapNodes(&head, current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

// Function to insert a new node in a sorted way by interchanging links
void sortedInsert(struct Node** head, struct Node* new_node) {
    if (*head == NULL || (*head)->data >= new_node->data) {
        new_node->next = *head;
        *head = new_node;
    }
    else {
        struct Node* current = *head;

        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
    }
}

// Insertion sort by interchanging links
void insertionSort(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    struct Node* sorted = NULL;
    struct Node* current = head;

    while (current != NULL) {
        struct Node* next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }

    head = sorted;
}

// Function to find the minimum node in a linked list starting from a given node
struct Node* findMinNode(struct Node* head) {
    struct Node* min = head;
    struct Node* current = head->next;

    while (current != NULL) {
        if (current->data < min->data)
            min = current;
        current = current->next;
    }

    return min;
}

// Selection sort by interchanging links
void selectionSort(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    struct Node* current = head;

    while (current != NULL) {
        struct Node* min = findMinNode(current);
        swapNodes(&head, current, min);
        current = current->next;
    }
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

    int choice;
    do {
        printf("Linked List: ");
        printList(head);
        printf("\nSorting Techniques:\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleSort(head);
                printf("After Bubble Sort: ");
                printList(head);
                break;
            case 2:
                insertionSort(head);
                printf("After Insertion Sort: ");
                printList(head);
                break;
            case 3:
                selectionSort(head);
                printf("After Selection Sort: ");
                printList(head);
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

    // Free the memory occupied by the linked list
    freeList(head);

    return 0;
}
