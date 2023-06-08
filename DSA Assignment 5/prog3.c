#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void bubbleSort(struct Node* head) {
    if (head == NULL)
        return;

    int swapped;
    struct Node* current;
    struct Node* last = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                swap(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

void sortedInsert(struct Node** head, struct Node* new_node) {
    struct Node* current;
      if (*head == NULL || (*head)->data >= new_node->data) {
        new_node->next = *head;
        *head = new_node;
    }
    else {
        current = *head;
        
        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }
        
        new_node->next = current->next;
        current->next = new_node;
    }
}

void insertionSort(struct Node** head) {
    struct Node* sorted = NULL;
    struct Node* current = *head;
    
    while (current != NULL) {
        struct Node* next = current->next;
        
        sortedInsert(&sorted, current);
        
        current = next;
    }
    
    *head = sorted;
}

void selectionSort(struct Node* head) {
    struct Node* current = head;
    struct Node* temp = NULL;

    while (current != NULL) {
        struct Node* min = current;
        struct Node* r = current->next;
        while (r != NULL) {
            if (r->data < min->data)
                min = r;
            r = r->next;
        }
        if (min != current)
            swap(min, current);
        current = current->next;
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
                insertionSort(&head);
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

    return 0;
}
