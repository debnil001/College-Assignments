#include <stdio.h>
#include <stdlib.h>

// Structure for a ListNode
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function for inserting ListNode in a sorted way
void sortedInsert(struct ListNode**, struct ListNode*);
// Function for insertion sort (linked list)
struct ListNode* insertionSort(struct ListNode* head)
{
    // Initialize sorted and current
    struct ListNode* sorted = NULL;
    struct ListNode* current = head;

    while (current != NULL)
    {
        // Store address for next iteration
        struct ListNode* next = current->next;
        // Insert current in new linked list
        sortedInsert(&sorted, current);
        // Update current
        current = next;
    }
    // Update head
    head = sorted;
    return head;
}

// Function to insert a new ListNode
void sortedInsert(struct ListNode** head, struct ListNode* new_node)
{
    struct ListNode* current;
    // For head
    if (*head == NULL || (*head)->val >= new_node->val)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        // Locating ListNode (tail)
        current = *head;
        while (current->next != NULL &&
               current->next->val < new_node->val)
        {
            current = current->next;
        }
        // Updating next
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Function to add a new ListNode at the end of the linked list
void add_node(struct ListNode** head, int val)
{
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct ListNode* current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print the data of the linked list
void print_data(struct ListNode* head)
{
    struct ListNode* current = head;
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
}

int main()
{
    struct ListNode* list1 = NULL;

    add_node(&list1, 2);
    add_node(&list1, 8);
    add_node(&list1, 5);
    add_node(&list1, 6);

    printf("Linked List: ");
    print_data(list1);

    printf("\nAfter Sorting: ");
    list1 = insertionSort(list1);
    print_data(list1);

    return 0;
}
