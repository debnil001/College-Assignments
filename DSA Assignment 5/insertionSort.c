#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode* dummy = createNode(0);
    dummy->next = head;

    struct ListNode* prev = head;
    struct ListNode* curr = head->next;

    while (curr != NULL){
        if (curr->val >= prev->val) {
            prev = curr;
            curr = curr->next;
            continue;
        }
        struct ListNode* start = dummy;
        while (curr->val > start->next->val) {
            start = start->next;
        }
        prev->next = curr->next;
        curr->next = start->next;
        start->next = curr;
        curr = prev->next;
    }
    return dummy->next;
}

struct ListNode* bubbleSort(struct ListNode* head){
    struct ListNode* dummy =createNode(0);
    dummy->next=head;
    struct ListNode* curr = head;
    while(curr!=NULL){

    }
}
void swapNodes(struct ListNode** headRef, struct ListNode* prevNode1,
 struct ListNode* node1, struct ListNode* prevNode2, struct ListNode* node2) {
    // Check if node1 is the head of the list
    if (prevNode1 == NULL)
        *headRef = node2;
    else
        prevNode1->next = node2;
    if (prevNode2 == NULL)
        *headRef = node1;
    else
        prevNode2->next = node1;
    struct ListNode* temp = node2->next;
    node2->next = node1->next;
    node1->next = temp;
}

void selectionSort(struct ListNode** headRef) {
    struct ListNode* current = *headRef;
    struct ListNode* prevNode1, *node1, *prevNode2, *node2;
    struct ListNode* minNode;

    while (current != NULL && current->next != NULL) {
        minNode = current;
        prevNode1 = current;
        node1 = current;
        while (node1->next != NULL) {
            if (node1->next->val < minNode->val) {
                prevNode2 = prevNode1;
                node2 = node1->next;
                minNode = node1->next;
            }
            prevNode1 = node1;
            node1 = node1->next;
        }
        if (minNode != current) {
            swapNodes(headRef, prevNode1, node1, prevNode2, node2);
            current = minNode;
        }
        else {
            current = current->next;
        }
    }
}

void display(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct ListNode* head = createNode(5);
    head->next = createNode(3);
    head->next->next = createNode(8);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    printf("Linked List before sorting: ");
    display(head);

    selectionSort(&head);

    printf("Linked List after sorting: ");
    display(head);

    return 0;
}
